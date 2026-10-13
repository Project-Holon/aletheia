/*
 * function: NWM_GetDispersionScanPeriod
 * address:  0x02702998
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: data_02FFFC3C (ABS32 at +0xA0) has no witness.  It is a twl bss
 *   object (0x02732DA0..0x02735B40) with no ROM content, so sole-ref/self has
 *   no word to compare, and no pool word names it outside this range; there is
 *   no layout/data_objects.txt row for it either.
 *
 * symbols:
 *   func_02087C6C  0x02087C6C  arm twl
 *   data_02FFFC3C   0x02FFFC3C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02087C6C(u8 *);
extern u32 data_02FFFC3C[];

u16 NWM_GetDispersionScanPeriod(u32 a0) {
    u8 mac[6];
    u16 sum;
    int i;
    int v;
    func_02087C6C(mac);
    for (sum = i = 0; i < 6; i++) {
        sum += mac[i];
    }
    sum += (u16)data_02FFFC3C[0];
    v = sum * 13;
    if (a0 == 1) {
        return v % 10 + 0x1E;
    }
    return v % 10 + 0x69;
}
