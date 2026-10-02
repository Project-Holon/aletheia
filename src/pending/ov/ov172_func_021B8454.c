/*
 * function: func_021B8454
 * address: 0x021B8454
 * packet: pkt_ov172_021B8454
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note 2026-10-02: logic complete; only register allocation differs. The original spills `changed` to
 *   sp+0x14 (reloaded before the joinmask subtract) and keeps i<<6 in r6 in the remove path; this C keeps
 *   `changed` in r6 (merged with the dirty=1 constant) and spills i<<6. Inert: decl order, u8/u32/enum
 *   changed, int i, block-scoped base. func_0203D1A4 declared u8 (body returns x & 0xff): needed so
 *   self reaches func_021BE0A8 untruncated.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_0203D1C0 0x0203D1C0 arm
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_0203E808 0x0203E808 arm
 *   func_021B7B20 0x021B7B20 thumb ov172
 *   func_0203E8C8 0x0203E8C8 arm
 *   func_021B8614 0x021B8614 thumb ov172
 *   func_021BE058 0x021BE058 thumb ov172
 *   func_021BE0A8 0x021BE0A8 thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    int on;
    int pad68[2];
    int self;
    int pad74;
    u8 slot;
    u8 pad79[3];
    int dirty;
    u8 pad80[0x24];
} Player;
typedef struct {
    u8 pad0[0x64];
    Player pl[4];
    u32 slotarg[3];
    u8 slotmask;
    u8 pad171[0x11];
    u8 joinmask;
    u8 pad183[0x11];
    u32 w194;
    u8 pad198[0x216];
    u8 leader;
} Q;
extern u32 func_020399A8(void);
extern u8 func_0203D1A4(u32 v);
extern u16 func_021BE00C(u16 *p);
extern u32 func_0203D1C0(u32 index);
extern u32 func_021BDFDC(void *p);
extern void func_0203E808(int a0, int a1, int a2, int a3);
extern void func_021B7B20(int unused, char *base, int i);
extern void func_0203E8C8(unsigned int idx);
extern void func_021B8614(int unused, int unused2, void *p);
extern void func_021BE058(void *p, u8 v);
extern void func_021BE0A8(void *p, u8 v);
extern void func_021B7740(void *p, char *q, int a, int b);
void func_021B8454(void *p, Q *q)
{
    u8 count;
    int changed;
    u8 self;
    u16 id;
    char *base;
    u8 i;
    u8 k;
    count = 0;
    changed = 0;
    self = func_0203D1A4(func_020399A8());
    id = func_021BE00C(p);
    for (i = 0; i < 4; i++) {
        if (func_0203D1C0(i) == 1) {
            if (q->pl[i].on == 0) {
                base = (char *)func_021BDFDC(p);
                q->pl[i].on = 1;
                if (i == self) {
                    q->pl[i].self = 1;
                } else {
                    for (k = 0; k < 3; k++) {
                        if (!(q->slotmask & (1 << k))) {
                            func_0203E808(3 << 14, i, id, q->slotarg[k]);
                            q->slotmask |= (u8)(1 << k);
                            q->pl[i].slot = k;
                            break;
                        }
                    }
                }
                q->joinmask |= (u8)(1 << i);
                q->pl[i].dirty = 1;
                func_021B7B20((int)p, base, i);
                changed = 1;
                count++;
            }
        } else {
            if (q->pl[i].on == 1) {
                q->pl[i].on = 0;
                if (q->pl[i].self == 0) {
                    func_0203E8C8(i);
                    q->slotmask -= (u8)(1 << q->pl[i].slot);
                }
                if (q->leader == i) {
                    q->w194 = 0;
                    changed = 1;
                }
                q->joinmask -= (u8)(changed << i);
                func_021B8614((int)p, (int)q, &q->pl[i]);
            }
        }
    }
    if (changed == 1) {
        func_021BE058(p, count);
        func_021BE0A8(p, self);
        func_021B7740(p, (char *)func_021BDFDC(p), 0, 1);
    }
}
