/*
 * function: DSP_EnumSections
 * address:  0x02705980
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSPi_ReadProcessImage 0x027053D4 arm twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct Chan {
    u32 pad[5];
    void *file;
    u16 f18;
    u16 f1a;
    u32 f1c;
    u32 busy[2];
    u32 tabA[8];
    u32 tabB[8];
} Chan;
typedef struct Hdr {
    u16 pad0;
    u16 count;
    u32 pad4;
    u32 f8;
    u32 fC;
    u16 base;
} Hdr;
typedef struct Ent {
    u32 name0;
    u32 nameOff;
    u32 f8;
    u32 fC;
    u32 len;
    u32 off;
    u32 pad18[3];
    u32 flags;
} Ent;

u32 DSPi_ReadProcessImage(Chan *p, u32 a, void *buf, s32 len);

u32 DSP_EnumSections(Chan *c, s32 (*cb)(Chan *, Hdr *, Ent *))
{
    Hdr h;
    Ent e;
    s32 i = 0;
    if (DSPi_ReadProcessImage(c, 0, &h, 0x14)) {
        u32 base = h.base + 0x14;
        for (; i < h.count; i++) {
            if (!DSPi_ReadProcessImage(c, base + i * 0x28, &e, 0x28)) {
                break;
            }
            if (!(e.flags & 0x80) && e.len != 0 && cb != 0) {
                if (!cb(c, &h, &e)) {
                    break;
                }
            }
        }
        i = i >= h.count;
    }
    return i;
}
