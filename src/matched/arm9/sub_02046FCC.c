/*
 * function: G3D_SYSTEM_CutTexture
 * address:  0x02046FCC
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGetTex  0x0206E964  arm
 *   func_020307E0  0x020307E0  arm
 *
 * Shrink the 0x48BF-tagged object's buffer to exactly what it holds:
 * 0x0206E964 walks the buffer and returns the address of its last record,
 * that record's own length lives at +0x14, and the new size handed to the
 * heap trimmer at 0x020307E0 is the distance from the buffer's base to the
 * end of that record.
 *
 * The returned pointer is copied out of r0 into r2 before it is used, which
 * is the tell that it is a named local and not an inline call argument
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046FCC.c \
 *       --func G3D_SYSTEM_CutTexture --addr 0x02046FCC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct Record {
    u8  pad00[0x14];
    u32 size;
};

extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void func_020307E0(void *p, u32 size);

void G3D_SYSTEM_CutTexture(struct Tagged *p)
{
    void          *buf = p->buf;
    struct Record *last = (struct Record *)NNS_G3dGetTex(buf);

    func_020307E0(buf, (u32)((u8 *)last + last->size - (u8 *)buf));
}
