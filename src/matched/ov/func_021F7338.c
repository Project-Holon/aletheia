/*
 * function: func_021F7338
 * address:  0x021F7338
 * packet:   pkt_021F7338
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *
 * Return the slot record for a kind: kind 9 is the current 0x128-byte
 * entry of the +0x20C array (index at +0xD4), kinds 10 and 8 share the
 * record at +0xE4. Any other kind reports through func_02034714 (raw
 * address 0x02203B80, a plain constant as in func_02202B20) and yields 0.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 data[0x128];
} Entry;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0xE4 - 0xD8];
    Entry single;
    Entry arr[1];
} Obj;

extern void func_02034714(const char *expr, u32 line, const char *file);

Entry *func_021F7338(Obj *p, int kind)
{
    if (kind == 9) {
        return &p->arr[p->cur];
    } else if (kind == 10) {
        return &p->single;
    } else if (kind == 8) {
        return &p->single;
    }
    func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
    return 0;
}
