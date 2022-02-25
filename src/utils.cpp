#include "common.h"

#ifdef VITA
#include <psp2/ctrl.h>
#endif

int distance(int x1, int y1, int x2, int y2)
{
	return sq(x1 - x2) + sq(y1 - y2);
}

Enemy* findNearestEnemy(Fixed x, Fixed y)
{
	static Enemy* nearest;
	static Enemy* ce;
	
	// Find first if there are any living enemy
	bool hasLivingEnemy = false;
	
	for(int i = 0; i < MAX_ENEMY; i++)
	{
		ce = &Level::enemiesArray->data[i];
		if(ce->isActive() && ce->isDamageable())
		{
			hasLivingEnemy = true;
			nearest = ce;
			break;
		}
	}
	
	// If not, do nothing
	if(!hasLivingEnemy)
		return NULL;
	else
	{
		// If yes, find the actual nearest enemy
		int lastDistance = distance(fixtoi(nearest->getx()), fixtoi(nearest->gety()), fixtoi(x), fixtoi(y));
		int concurrentDistance;
		
		for(int i = 0; i < MAX_ENEMY; i++)
		{
			ce = &Level::enemiesArray->data[i];
			if(ce->isActive() && ce->isDamageable())
			{
				concurrentDistance = distance(iToScreenX(fixtoi(ce->getx()), ce->getCamRel()),
											  iToScreenY(fixtoi(ce->gety()), ce->getCamRel()),
											  fixtoi(x), fixtoi(y));
				if(concurrentDistance < lastDistance)
				{
					nearest = ce;
					lastDistance = concurrentDistance;
				}
			}
		}
		return nearest;
	}
}

bool collidePointRect(Fixed px, Fixed py, Fixed x, Fixed y, int w, int h)
{
	return px >= x - itofix(w) / 2 && px < x + itofix(w) / 2 && py >= y - itofix(h) / 2 && py < y + itofix(h) / 2;
}

int isKeyPressed(t_key _k)
{
#ifdef VITA
	if (_k == SDL_SCANCODE_ESCAPE) {
		return (uint32_t)G_keys & SCE_CTRL_SELECT ? 1 : 0;
	} else if (_k == SDL_SCANCODE_RETURN) {
		return (uint32_t)G_keys & SCE_CTRL_CROSS ? 1 : 0;
	} else if (_k == G_upKey) {
		return (uint32_t)G_keys & SCE_CTRL_UP ? 1 : 0;
	} else if (_k == G_downKey) {
		return (uint32_t)G_keys & SCE_CTRL_DOWN ? 1 : 0;
	} else if (_k == G_leftKey) {
		return (uint32_t)G_keys & SCE_CTRL_LEFT ? 1 : 0;
	} else if (_k == G_rightKey) {
		return (uint32_t)G_keys & SCE_CTRL_RIGHT ? 1 : 0;
	} else if (_k == G_fireKey) {
		return (uint32_t)G_keys & SCE_CTRL_RTRIGGER ? 1 : 0;
	} else if (_k == G_fragmentKey) {
		return (uint32_t)G_keys & SCE_CTRL_LTRIGGER ? 1 : 0;
	} else if (_k == G_polarityKey) {
		return (uint32_t)G_keys & SCE_CTRL_SQUARE ? 1 : 0;
	} else if (_k == G_pauseKey) {
		return (uint32_t)G_keys & SCE_CTRL_START ? 1 : 0;
	} else {
		return 0;
	}
#else
	return G_keys[_k];
#endif
}

KeyEvent getk(void)
{
	static KeyEvent k;
	k = isKeyPressed(G_pauseKey);
	k <<= 4;
	k |= (((((isKeyPressed(SDL_SCANCODE_ESCAPE) << 1) + isKeyPressed(G_fragmentKey)) << 1) + isKeyPressed(G_polarityKey)) << 1) + isKeyPressed(G_fireKey);
	k <<= 4;
	k |= (((((isKeyPressed(G_upKey) << 1) + isKeyPressed(G_rightKey)) << 1) + isKeyPressed(G_leftKey)) << 1) + isKeyPressed(G_downKey);
	return k;
}

int iToScreenX(int x, int camRel)
{
	return (camRel == CAMREL_ABSOLUTE ? x - DC->cam.absX : (camRel == CAMREL_RELATIVE ? x - DC->cam.relX : x));
}
int iToScreenY(int y, int camRel)
{
	return (camRel == CAMREL_ABSOLUTE ? y - DC->cam.absY : (camRel == CAMREL_RELATIVE ? y - DC->cam.relY : y));
}
Fixed fToScreenX(Fixed x, int camRel)
{
	return (camRel == CAMREL_ABSOLUTE ? x - itofix(DC->cam.absX) : (camRel == CAMREL_RELATIVE ? x - itofix(DC->cam.relX) : x));
}
Fixed fToScreenY(Fixed y, int camRel)
{
	return (camRel == CAMREL_ABSOLUTE ? y - itofix(DC->cam.absY) : (camRel == CAMREL_RELATIVE ? y - itofix(DC->cam.relY) : y));
}
