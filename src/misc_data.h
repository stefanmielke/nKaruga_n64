#ifndef INC_MISC
#define INC_MISC

static const char string_nKaruga_config[] = "nKaruga.cfg";

static const char string_title[] = "Press Enter to start or Escape to quit";

static const char string_continue[] = "Continue ? (Enter/Esc : yes/no)";

static const char* string_bools[] = { "no\n", "yes\n" };

#ifdef VITA
#define TITLE_OPTIONS 3
#else
#define TITLE_OPTIONS 4
#endif
static const char* string_options[TITLE_OPTIONS] = {
	"nPlay\n",
	"iDifficulty:",
	"bUse arrow keys:",
#ifndef VITA // Causes a crash somehow
	"nConfigure controls\n"
#endif
};

#define KEYS_TO_BIND 4
static const char *string_keys[KEYS_TO_BIND] = {
	"Fire\n",
	"Switch polarity\n",
	"Release power\n",
	"Pause the game\n"
};

static const char *string_difficulties[] = {
	"Easy\n",
	"Normal\n",
	"Hard\n"
};

const static char *string_results[6] = {
	"BATTLE REPORT\n\n\n",
	"Boss destroy bonus\n\n",
	"Score (this chapter)\n\n",
	"Max ",
	" chains\n\n",
	"Grade\n\n"
};

const static int power_fill_offsets[] = { 1, 2, 1, 5, 1, 8, 1, 10, 1, 10, 1, 10, 1, 10, 3, 10, 6, 10, 9, 10 };
#endif