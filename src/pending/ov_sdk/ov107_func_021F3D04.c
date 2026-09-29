typedef struct {
    char *romFilePathp;
    unsigned short *gameNamep;
    unsigned short *gameIntroductionp;
    char *iconCharPathp;
    char *iconPalettePathp;
    unsigned long ggid;
    unsigned char maxPlayerNum;
    unsigned char pad[3];
    unsigned char userParam[32];
} MBGameRegistry;

extern void func_02082A48(unsigned short data, void *destp, unsigned long size);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_02082AC0(unsigned long data, void *destp, unsigned long size);
extern int func_021F3DF4(char *filePathp, void *iconp, int char_flag);
extern int func_021F3F0C(unsigned short *str);

void func_021F3D04(unsigned char *gameInfop, MBGameRegistry *mbGameRegp, void *parent)
{
    int len;
    int icon_disable;
    int icon_disable2;

    func_02082A48(0, gameInfop, 0x4C0);
    gameInfop[0x4B2] = 0;
    icon_disable = func_021F3DF4(mbGameRegp->iconCharPathp, gameInfop, 1) == 0;
    icon_disable2 = func_021F3DF4(mbGameRegp->iconPalettePathp, gameInfop, 0) == 0;
    icon_disable = icon_disable | icon_disable2;
    if (icon_disable) {
        gameInfop[0x4B2] = 1;
        func_02082AC0(0, gameInfop, 0x220);
    }
    *(unsigned long *)(gameInfop + 0x4B8) = mbGameRegp->ggid;
    if (parent)
        func_02082A60(parent, gameInfop + 0x220, 0x16);
    gameInfop[0x236] = mbGameRegp->maxPlayerNum;
    len = func_021F3F0C(mbGameRegp->gameNamep);
    func_02082A60(mbGameRegp->gameNamep, gameInfop + 0x238, (unsigned short)(len * 2));
    func_02082A60(mbGameRegp->gameIntroductionp, gameInfop + 0x298, 0xC0);
    gameInfop[0x358] = 1;
    *(unsigned short *)(gameInfop + 0x35A) = 1;
    *(unsigned short *)(gameInfop + 0x4B0) = 1;
}
