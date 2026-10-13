/*
 * function: STARTMENU_ConfigPromptReadInput
 * address:  0x021BC8AC
 * packet:   pkt_ov088_021BC8AC
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   STARTMENU_ConfigPromptHighlightChoice  0x021BC870  thumb  ov088
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   d_021BD83C     0x021BD83C  data  a1
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct C12 {
    char c[12];
} C12;

extern C12 d_021BD83C;

extern u32 KEY_GetTrg(void);
extern void STARTMENU_ConfigPromptHighlightChoice(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int TOUCHPANEL_HitTrg(const void *p);

int STARTMENU_ConfigPromptReadInput(u8 *p)
{
    int r;
    u32 k;
    int t;
    C12 s;

    if ((KEY_GetTrg() & 0x40) || (KEY_GetTrg() & 0x80)) {
        if (p[0] == 0)
            p[0] = 1;
        else
            p[0] = 0;
        STARTMENU_ConfigPromptHighlightChoice(p);
        GFL_USE_PlaySeDefaultVolume(0x548);
    }
    k = KEY_GetTrg();
    r = 1;
    if (k & r) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (p[0] != 0)
            r = 2;
        return r;
    }
    s = d_021BD83C;
    t = TOUCHPANEL_HitTrg(&s);
    if (t != -1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return t == 0 ? 1 : 2;
    }
    return 0;
}
