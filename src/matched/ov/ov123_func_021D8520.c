/*
 * function: func_021D8520
 * address: 0x021D8520
 * packet: pkt_ov123_021D8520
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020071D8 is unlabelled and lacks an outside witness;
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 * blocker: 0x020071D8 Thumb, verified EXACT in blocker-71D8-r1.log:
 *   extern unsigned int BACKUP_SYSTEM_GetWork(void *, int *);
 *   unsigned int SAVE_CONTROL_GetWorkArea(char *p, int *out) {
 *       return BACKUP_SYSTEM_GetWork(*(void **)(p + 0x10), out);
 *   }
 *   symbols: BACKUP_SYSTEM_GetWork 0x02031994 arm
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8490 0x021D8490 thumb ov123
 */
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
struct Ctrl020071D8;
extern void *SAVE_CONTROL_GetWorkArea(struct Ctrl020071D8 *ctrl, int *out);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8490(char *p);
void func_021D8520(char *p)
{
    int x;
    unsigned int v;
    if (GFL_NET_GetRunState()) {
        if (func_021B95D4(9,*(void **)(p+0x10))) {
            v=(unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p+0x28),&x);
            func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
            if (!func_021B9748(*(void **)(p+0x10)))
                func_021D6EE0((u8 *)p,(int)func_021D8490,0x6fa);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            func_021D6EE0((u8 *)p,(int)func_021D8490,0x700);
    }
}
