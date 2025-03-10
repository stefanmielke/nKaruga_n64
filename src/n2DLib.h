#ifndef INCLUDE_GRAFX
#define INCLUDE_GRAFX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

#define BUFF_BYTES_SIZE (320*240*2)
extern unsigned short *BUFF_BASE_ADDRESS;
extern SDL_Texture *MAIN_SCREEN;

#if defined(__cplusplus) && !defined(min) && !defined(max)
inline int min(int a, int b)
{
	return a < b ? a : b;
}
inline int max(int a, int b)
{
	return a > b ? a : b;
}
#endif

#define MAX_TIMER 2

typedef int Fixed;

typedef struct
{
	int x;
	int y;
	int h;
	int w;
} Rect;

typedef Uint8 t_key;
#define itofix(x) ((x) << 8)
#define fixtoi(x) ((x) >> 8)
#define fixdiv(x, y) (((x) << 8) / (y))
#define clamp(x, a, b) min(max(x, a), b)
#define sign(x) ((x) < 0)
#define fixsin(x) fixcos((x) - 64)

#ifdef __cplusplus
extern "C" {
#endif

extern Fixed fixmul(Fixed x, Fixed y);
extern Fixed fixcos(Fixed angle);
extern void rotate(int x, int y, int cx, int cy, Fixed angle, Rect* out);
extern void getBoundingBox(int x, int y, int w, int h, int cx, int cy, Fixed angle, Rect *out);
extern int sq(int);
extern Fixed fixsq(Fixed);
extern int cube(int);
extern Fixed fixcube(Fixed);
extern int interpolatePathFloat(int, float[], float[], int[], int, Rect*);

extern void initBuffering();
extern void constrainFrameRate(int);
extern void displayFrameRate();
extern void updateScreen();
extern void updateKeys();
extern void deinitBuffering();
extern void timer_load(unsigned, Uint32);
extern Uint32 timer_read(unsigned);
extern void clearBufferB();
extern void clearBufferW();
extern void clearBuffer(unsigned short);
#if !defined VITA && !defined N64
extern unsigned short getPixelUnsafe(const unsigned short*, unsigned int, unsigned int);
extern unsigned short getPixel(const unsigned short*, unsigned int, unsigned int);
extern void setPixelUnsafe(unsigned int, unsigned int, unsigned short);
extern void setPixel(unsigned int, unsigned int, unsigned short);
extern void setPixelRGB(unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
#else
static inline unsigned short getPixelUnsafe(const unsigned short *src, unsigned int x, unsigned int y)
{
	return src[x + y * src[0] + 3];
}

static inline unsigned short getPixel(const unsigned short *src, unsigned int x, unsigned int y)
{
	if(x < src[0] && y < src[1])
		return src[x + y * src[0] + 3];
	else
		return src[2];
}

#define setPixelUnsafe(x, y, c) *((unsigned short*)BUFF_BASE_ADDRESS + (x) + (y) * 320) = c;

static inline void setPixel(unsigned int x, unsigned int y, unsigned short c)
{
	if(x < 320 && y < 240)
		*((unsigned short*)BUFF_BASE_ADDRESS + x + y * 320) = c;
}

static inline void setPixelRGB(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
{
	if(x < 320 && y < 240)
		*((unsigned short*)BUFF_BASE_ADDRESS + x + y * 320) = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
}
#endif
extern void drawHLine(int, int, int, unsigned short);
extern void drawVLine(int, int, int, unsigned short);
extern void fillRect(int, int, int, int, unsigned short);
extern void drawSprite(const unsigned short*, int, int, int, unsigned short);
extern void drawSpritePart(const unsigned short*, int, int, const Rect*, int, unsigned short);
extern void drawSpriteScaled(const unsigned short*, const Rect*, int, unsigned short);
extern void drawSpriteRotated(const unsigned short*, const Rect*, const Rect*, Fixed, int, unsigned short);
extern void drawLine(int, int, int, int, unsigned short);
extern void drawPolygon(unsigned short, int, ...);
extern void fillCircle(int, int, int, unsigned short);
extern void fillEllipse(int, int, int, int, unsigned short);
extern void drawString(int*, int*, int, const char*, unsigned short, unsigned short);
extern void drawDecimal(int*, int*, int, unsigned short, unsigned short);
extern void drawChar(int*, int*, int, char, unsigned short, unsigned short);
extern void drawStringF(int*, int*, int, unsigned short, unsigned short, const char*, ...);
extern int numberWidth(int);
extern int stringWidth(const char*);
extern void wait_no_key_pressed(t_key);
extern int get_key_pressed(t_key*);
extern int isKey(t_key, t_key);

extern unsigned short *loadBMP(const char*, unsigned short);

// Global key state
extern const t_key *G_keys;
#ifdef __cplusplus
}
#endif

#endif
