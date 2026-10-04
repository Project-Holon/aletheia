/*
 * function: func_021BDB30
 * address: 0x021BDB30
 * packet: pkt_ov099_021BDB30
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: BCB70 matched callers declare void; original consumes r0 after BL, so the return is int here. 399A8 own void tail-forwarder leaves r0 live and caller passes that result to D1E8/39C68. BDD54 own u8 return is widened to retain the original explicit u16 truncation.
 * symbols:
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BC104 0x021BC104 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203D798 0x0203D798 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_0203D378 0x0203D378 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BDD54(char *, void *);
extern void func_021BC104(char *);
extern void func_021C24A4(void *, int);
extern void func_021BAADC(char *, int, int);
extern int func_021BCB70(int, int, int *);
extern int func_021BCBBC(int, int, int *);
extern void func_021BAAB8(char *, int, int);
extern void *func_0203D798(void);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_0203D1E8(u32, void *);
extern u32 func_0203D378(void);
struct Link;
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
int func_021BDB30(char *p, int v)
{
    u16 state;
    int out;
    state = (u16)func_021BDD54(p, *(void **)(p + 8));
    switch (state) {
    case 4:
        func_0203D798();
        func_021BC104(p);
        func_021C24A4(p, 0);
        func_021BAADC(p, 0x7b, 0);
        *(u8 *)(p + 0x1355) = 0;
        *(u32 *)(p + 0x1cc) = 0x10;
        return v;
    case 5:
        *(u32 *)(p + 0x1d0) = state;
        return 2;
    case 6:
        func_021BC104(p);
        *(u32 *)(p + 0x1d0) = state;
        return 2;
    default:
        func_0203D1E8((u32)func_020399A8(), 0);
        if (func_0203D378()) {
            if (func_021BCB70(*(int *)(p + 0x1348), *(int *)(p + 0xc4), &out) &&
                func_021BCBBC(*(int *)(p + 0x1348), *(int *)(p + 0xcc), &out)) {
                func_021BAAB8(p, 0x68, 0);
                *(u32 *)(p + 0x1cc) = 0x74;
                return v;
            }
            *(u32 *)(p + 0x1cc) = 0x5b;
        } else {
            func_02039C68((void *)func_020399A8(), 0x1b, 0xa);
            *(u32 *)(p + 0x1cc) = 0x49;
        }
        return v;
    }
}
