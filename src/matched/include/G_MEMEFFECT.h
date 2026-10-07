#ifndef ALETHEIA_G_MEMEFFECT_H
#define ALETHEIA_G_MEMEFFECT_H
/* g_021DE67C (arm9) */
struct MEMEFFECT {
    void *param_0_task;
    signed short count;
    unsigned short max;
    unsigned char index;
    unsigned char active;
    unsigned char pad_A[0x2];
    void *param_1_task;
    signed short param_1_conut;
    unsigned short param_1_frame;
    unsigned char param_1_kind;
    unsigned char param_1_flag;
};
#endif
