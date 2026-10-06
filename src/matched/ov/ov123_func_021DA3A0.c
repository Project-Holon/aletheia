/*
 * function: func_021DA3A0
 * address: 0x021DA3A0
 * packet: pkt_ov123_021DA3A0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: 0x020071D8 ARM9 leaf has no outside witness; verified EXACT
 *   in scratch blocker071d8-r1.log, 12 bytes. Ilias owns filing it.
 *   extern unsigned func_02031994(void *, unsigned *);
 *   symbols: func_02031994 0x02031994 arm
 *   unsigned func_020071D8(char *p, unsigned *out) {
 *       return func_02031994(*(void **)(p + 0x10), out);
 *   }
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_020362DC 0x020362DC arm
 *   func_020071D8 0x020071D8 thumb
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA328 0x021DA328 thumb ov123
 */
extern int func_0203CD98(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020362DC(void);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
struct Ctrl020071D8;
extern void *func_020071D8(struct Ctrl020071D8 *ctrl, int *out);
extern void func_021DA034(char *p, int n, int unused);
extern void func_021DA328(char *p);
void func_021DA3A0(char *p)
{
    int a;
    unsigned b;
    if (func_0203CD98()) {
        if (func_021B95D4(9,*(void **)(p + 8))) {
            b = (unsigned int)func_020071D8(*(void **)(p + 0x1c),&a);
            func_021BE79C((void *)func_021B973C(*(void **)(p + 8)),(void *)b,0x80000);
            if (!func_021B9748(*(void **)(p + 8))) {
                func_021DA034(p,(int)func_021DA328,0x1f6);
                return;
            }
        }
    } else if (func_020362DC()) {
        func_021DA034(p,(int)func_021DA328,0x1fc);
    }
}
