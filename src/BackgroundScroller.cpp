#include "common.h"

void cb_bgHandle_default(BackgroundScroller *bg)
{
	bg->dy += itofix(1);
}

void cb_bgHandle_2_2(BackgroundScroller *bg)
{
	bg->dy += itofix(1);
	// Here, the background scrolling is reset to 0 every time a period is completed to avoid rounding errors
	// The formula is
	// period = itofix(background_2_4.width) / background_2_4.speed
	if(bg->dy >= itofix(120 * 256 / 192)) // might as well avoid using fixdiv
		bg->dy = 0;
}

backgroundHandle bgHandle[] = { cb_bgHandle_default, cb_bgHandle_2_2 };

BackgroundScroller::BackgroundScroller(unsigned short *bg, Fixed _x, Fixed _y, Fixed sscale, Fixed dscale, int bgHandleID) // x is left-top corner, y is center (ugly but purpose-built)
{
	img = &(bg[3]);
	w = bg[0];
	h = bg[1];
	colorKey = bg[2];
	x = itofix(_x);
	y = itofix(_y - h / 2);
	dx = 0;
	dy = 0;
	scrollScale = sscale;
	displayScale = dscale;
	handle = bgHandle[bgHandleID];
	
	Fixed sourceX = -((x + fixmul(dx, scrollScale)) % itofix(w)) + itofix(w);
	sourceX %= itofix(w);
	
	for(int sx = 0; sx < 320; sx++, sourceX = (sourceX + displayScale) % itofix(w))
	{
		scrollX[sx] = sourceX;
	}
}

BackgroundScroller::~BackgroundScroller()
{
}

void BackgroundScroller::draw()
{
	Fixed sourceY = -((y + fixmul(dy, scrollScale)) % itofix(h)) + itofix(h);
	sourceY %= itofix(h);
	
	for(int sy = 0; sy < 240; sy++, sourceY = (sourceY + displayScale) % itofix(h))
	{
		for(int sx = 0; sx < 320; sx++)
		{
			unsigned short c = img[fixtoi(sourceY) * w + fixtoi(scrollX[sx])];
			if (c != colorKey)
				setPixelUnsafe(sx, sy, c);
		}
	}
}

void BackgroundScroller::update()
{
	(handle)(this);
}
