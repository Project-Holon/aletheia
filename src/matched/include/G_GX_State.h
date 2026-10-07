#ifndef ALETHEIA_G_GX_STATE_H
#define ALETHEIA_G_GX_STATE_H
/* gGXState (arm9) */
struct GX_State {
    unsigned short vramCnt_lcdc;
    unsigned short vramCnt_bg;
    unsigned short vramCnt_obj;
    unsigned short vramCnt_arm7;
    unsigned short vramCnt_tex;
    unsigned short vramCnt_texPltt;
    unsigned short vramCnt_clrImg;
    unsigned short vramCnt_bgExtPltt;
    unsigned short vramCnt_objExtPltt;
    unsigned short vramCnt_sub_bg;
    unsigned short vramCnt_sub_obj;
    unsigned short vramCnt_sub_bgExtPltt;
    unsigned short vramCnt_sub_objExtPltt;
};
#endif
