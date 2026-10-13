/*
 * function: func_021E6E38
 * address: 0x021E6E38
 * packet: pkt_ov093_021E6E38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 202 bytes of code followed by 2-byte alignment nop at 021E6F02,
 * then the labelled Thumb veneer func_021E6F04.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C815C 0x021C815C thumb ov093
 *   func_021B8C20 0x021B8C20 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021C804C 0x021C804C thumb ov093
 *   func_021C814C 0x021C814C thumb ov093
 *   func_021C8374 0x021C8374 thumb ov093
 *   func_021D8340 0x021D8340 thumb ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   func_021E6F04 0x021E6F04 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C815C(int *p);
extern u8 func_021B8C20(int, u32, u32);
struct UtilWork;
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021C804C(void *, u8, u32 *);
extern int func_021C814C(u8 *p, int v);
extern int func_021C8374(u8 *p, int i);
extern u32 func_021D8340(u32 *);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int func_021E6F04(u32);
extern int func_021D76BC(int, u32);
void func_021E6E38(void *x, void *a, int c, u8 *d)
{
    u8 k;
    u8 v;
    u32 flags;
    u32 desc;
    u32 id;
    int ok;
    if (c == func_021D775C(2)) {
        k = func_021D775C(14);
        if (k == 6) {
            flags = func_021C7D00(a, c);
            k = func_021B8C20(func_021C815C(a), flags, 0);
        }
        if (func_021C7F68(a, k, d) != 0) {
            void *m;
            m = func_021C7CF4(a, *d);
            v = *d;
            ok = 0;
            if (func_021D5BB0(m, 3) == 0) {
                if (func_021C804C(a, v, &desc) != 0) {
                    if (func_021C814C(a, v) != 0) {
                        if (func_021C8374(a, v) == 0) {
                            id = func_021D8340(&desc);
                            if (id != 0 && WAZA_TOOL_IsDamaging((void *)id) != 0 && func_021E6F04(id) == 0)
                                ok = 1;
                        }
                    }
                }
            }
            if (ok != 0) {
                func_021D76BC(18, id);
                func_021D76BC(13, k);
                return;
            }
        }
        func_021D76BC(65, 1);
    }
}
