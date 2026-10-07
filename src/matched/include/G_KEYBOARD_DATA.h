#ifndef ALETHEIA_G_KEYBOARD_DATA_H
#define ALETHEIA_G_KEYBOARD_DATA_H
/* keyboard_data (arm9) */
struct KEYBOARD_DATA {
    unsigned char *KEY_OUT[3];
    unsigned short *KEY_CHR[3];
    int SKEY_TOUCH_SND[4];
};
#endif
