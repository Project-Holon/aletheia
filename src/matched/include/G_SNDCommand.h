#ifndef ALETHEIA_G_SNDCOMMAND_H
#define ALETHEIA_G_SNDCOMMAND_H
/* sCommandArray (arm9) */
struct SNDCommand {
    struct SNDCommand *next;
    int id;
    unsigned int arg[4];
};
#endif
