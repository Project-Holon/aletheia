/*
 * function: func_021F11F0
 * address:  0x021F11F0
 * packet:   pkt_ov107_021F11F0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef struct {
    unsigned int f00;
    unsigned char f04;
} Ov107Msg;

typedef signed int     s32;
typedef unsigned int   u32;
struct Entry;
u32 func_0203D378(void);
struct Entry *func_0203996C(s32 idx);
struct Entry *func_020399A8(void);
int func_0203D3F8(void *obj, int a, int b, int c, void *msg, int d, int e, int f);

int func_021F11F0(void *p, unsigned char kind, unsigned int val)
{
    Ov107Msg msg;
    void *obj;

    if (func_0203D378() == 1) {
        obj = func_0203996C(0xFF);
    } else {
        obj = func_020399A8();
    }
    msg.f04 = kind;
    msg.f00 = val;
    return func_0203D3F8(obj, 0xFF, 0x400, 8, &msg, 1, 0, 0);
}
