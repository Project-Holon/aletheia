/*
 * function: func_021D7130
 * address: 0x021D7130
 * packet: pkt_ov123_021D7130
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D70BC 0x021D70BC thumb ov123
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D580C(char *);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D70BC(char *);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 v);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
void func_021D7130(char *p)
{
    if (func_021D580C(*(char **)(p + 0x18)) != 0) {
        int n = *(int *)(p + 0x78) - 1;
        *(int *)(p + 0x78) = n;
        if (n <= 0) {
            if (n == 0) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPlayerParam(0);
                GFL_USE_FadeInBgmFull(6);
            }
            if (func_020362DC() != 0 || TOUCHPANEL_GetTrg() != 0) {
                func_021D6EE0((u8 *)p, (int)func_021D70BC, 0x20B);
            }
        }
    }
}
