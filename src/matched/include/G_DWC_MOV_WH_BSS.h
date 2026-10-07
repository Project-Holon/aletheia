#ifndef ALETHEIA_G_DWC_MOV_WH_BSS_H
#define ALETHEIA_G_DWC_MOV_WH_BSS_H
/* dwc_mov_wh_bss (arm9) */
struct DWC_MOV_WH_BSS {
    void (*wh_trace)();
    void *wh;
};
#endif
