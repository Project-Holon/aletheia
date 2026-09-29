/*
 * function: func_0217B264
 * address:  0x0217B264
 * packet:   pkt_ov019_0217B264
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02188CE0  0x02188CE0  thumb  ov021
 *   memcmp         0x0203EFC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0217B054  0x0217B054  thumb  ov019
 *   func_0217B098  0x0217B098  thumb  ov019
 *   func_0217B1D0  0x0217B1D0  thumb  ov019
 *   func_0217B370  0x0217B370  thumb  ov019
 *   func_0217B3EC  0x0217B3EC  thumb  ov019
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Entry {
    u8   pad0[7];
    u8   f7_lo : 4;
    u8   active : 1;
    u8   f7_hi : 3;
    u8   pad8[0x6C - 8];
    u16  h6C;
    u16  pad6E;
    void *slots[5];
    u8   pad84[8];
} Entry;

extern void *func_02012EBC(void *p);
extern u32   func_0200ED48(void *p);
extern u32   func_0201283C(void *p);
extern u32   func_02012964(void *p);
extern u32   func_02188CE0(void *p);
extern int   memcmp(const void *a, const void *b, u32 n);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  func_0217B054(u8 *w, Entry *e, void *p);
extern void  func_0217B098(u8 *w, u32 a, u32 b, u32 c, Entry *e);
extern int   func_0217B1D0(u8 *w, Entry *e);
extern int   func_0217B370(u8 *w, void *p, void *q);
extern void  func_0217B3EC(u8 *w, Entry *e);

void func_0217B264(u8 *w, void *sys, void *q)
{
    int i;
    int flag;
    u32 a;
    u32 b;
    u32 c;
    Entry *e;
    u8 buf[6] = {0, 0, 0, 0, 0, 0};

    flag = 0;
    a = func_0200ED48(func_02012EBC(sys));
    b = func_0201283C(sys);
    c = func_02188CE0(q);
    func_02012964(sys);
    if (memcmp(buf, w + 0x28A4, 6) != 0) {
        flag = 1;
    }
    e = (Entry *)(w + 0x2910);
    for (i = 0; i < 10; i++, e++) {
        if (e->active == 1) {
            int cnt;
            int j;
            void *p;

            func_0217B3EC(w, e);
            func_0217B098(w, a, b, c, e);
            if (flag == 1) {
                if (func_0217B1D0(w, e) == 1) {
                    flag = 0;
                }
            }
            cnt = 0;
            for (j = 0; j < 5; j++) {
                p = e->slots[j];
                if (p != 0) {
                    if (func_0217B370(w, p, q) == 0) {
                        func_0217B054(w, e, p);
                        e->slots[j] = 0;
                        cnt++;
                    }
                } else {
                    cnt++;
                }
            }
            if (cnt >= 5 && e->h6C == 0) {
                MI_CpuFill8(e, 0, sizeof(Entry));
            }
        }
    }
    MI_CpuFill8(w + 0x28A4, 0, 6);
}
