#include "common.h"

bool SoundHandle::launchLoop;

SoundHandle::SoundHandle()
{
#ifndef N64
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("Can't initialize audio : %s\n", Mix_GetError());
		exit(1);
	}
	Mix_AllocateChannels(32);
	loop = NULL;
	launchLoop = false;
#endif
}

SoundHandle::~SoundHandle()
{
#ifndef N64
	Mix_Quit();
#endif
}

void SoundHandle::update()
{
#ifndef N64
	if (launchLoop)
	{
		launchLoop = false;
		Mix_HookMusicFinished(NULL);
		Mix_PlayMusic(loop, -1);
	}
#endif
}

int SoundHandle::quickPlaySFX(Mix_Chunk *sfx)
{
#ifdef N64
	return 0;
#else
	return Mix_PlayChannel(-1, sfx, 0);
#endif
}

// Hook to branch the loop part of a music after the main part is done playing
void SoundHandle::hook_branch()
{
	launchLoop = true;
}

// loopM is guaranteed to be non-NULL
// If the songs consists only in a loop, mainM == NULL
int SoundHandle::playBgMusic(Mix_Music *mainM, Mix_Music *loopM)
{
	int r = 0;
#ifndef N64
	if (mainM)
	{
		Mix_HookMusicFinished(hook_branch);
		loop = loopM;
		r = Mix_PlayMusic(mainM, 1);
	}
	else
		r = Mix_PlayMusic(loopM, -1);
#endif
	return r;
}

void SoundHandle::setPausedBgMusic(bool pause)
{
#ifndef N64
	if (pause)
		Mix_PauseMusic();
	else
		Mix_ResumeMusic();
#endif
}

int SoundHandle::fadeOutMusic(int ms, void(*callback)())
{
#ifdef N64
	return 0;
#else
	Mix_HookMusicFinished(callback);
	return Mix_FadeOutMusic(ms);
#endif
}

int SoundHandle::stopBgMusic()
{
#ifdef N64
	return 0;
#else
	Mix_HookMusicFinished(NULL);
	return Mix_HaltMusic();
#endif
}

bool SoundHandle::musicPlaying()
{
#ifdef N64
	return false;
#else
	return Mix_PlayingMusic();
#endif
}