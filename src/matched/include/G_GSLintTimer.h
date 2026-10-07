#ifndef ALETHEIA_G_GSLINTTIMER_H
#define ALETHEIA_G_GSLINTTIMER_H
/* gTimers (arm9) */
struct GSLintTimer {
    unsigned int start;
    unsigned int total;
    unsigned int entries;
    unsigned int started;
};
#endif
