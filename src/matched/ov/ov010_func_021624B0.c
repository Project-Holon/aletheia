/*
 * function: EVENTDATA_SYSTEM_ReadEventFile
 * address:  0x021624B0
 * packet:   pkt_ov010_021624B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * pass 5 2026-10-06 P5L08: EXACT* (126 B code plus 2 B pad), also EXACT* under -lang c. The file is read
 * into o->size, then the header is parsed: o->p120 is the end of the data, and four sections follow the
 * four count bytes. Each section is its own block with a u8 count local, written in one uniform shape:
 * store the count, store the table pointer d + off, then add count * record size to off. The first
 * pointer is d + 0 (folded), the last section has no step. With this shape the zero offset, the 0x14
 * constant (r7) and h/d (r3/r2) get the original's colours; the earlier straight-line forms (one n local
 * per count, steps before the pointer stores, enum offset local) stayed at 54/126 or 102/128 in passes
 * 1 to 4.
 * symbols:
 *   func_02013ECC  0x02013ECC  thumb
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
struct ArcFile;

typedef struct {
    u8 n[4];
    u8 data[1];
} H;

typedef struct {
    int pad0;
    struct ArcFile *f4;
    u8 pad8[0xA];
    u16 c12;
    u16 c14;
    u16 c16;
    u16 c18;
    u16 pad1A;
    char *p1C;
    char *p20;
    char *p24;
    char *p28;
    u16 c2C;
    u16 c2E;
    u16 c30;
    u16 c32;
    u8 pad34[0x120 - 0x34];
    char *p120;
    int size;
    H hdr;
} O;

extern unsigned func_02013ECC(unsigned);
extern unsigned ARC_TOOL_GetHandleMemberSize(struct ArcFile *, unsigned);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *, unsigned, unsigned, unsigned, void *);


void EVENTDATA_SYSTEM_ReadEventFile(O *o, int x)
{
    int a;
    unsigned r;
    unsigned d;
    unsigned off;
    const H *h;

    a = func_02013ECC(x);
    r = ARC_TOOL_GetHandleMemberSize(o->f4, a);
    ARC_TOOL_ReadHandleMemberRange(o->f4, a, 0, r, &o->size);
    off = 0;
    h = &o->hdr;
    d = (unsigned)h + 4;
    o->p120 = (char *)h + o->size;
    {
        u8 n = h->n[0];
        o->c12 = n;
        o->p1C = (char *)(d + off);
        off += n * 0x14;
    }
    {
        u8 n = h->n[1];
        o->c14 = n;
        o->p20 = (char *)(d + off);
        off += n * 0x24;
    }
    {
        u8 n = h->n[2];
        o->c16 = n;
        o->p24 = (char *)(d + off);
        off += n * 0x14;
    }
    {
        u8 n = h->n[3];
        o->c18 = n;
        o->p28 = (char *)(d + off);
    }
    o->c2C = o->c12;
    o->c2E = o->c14;
    o->c30 = o->c16;
    o->c32 = o->c18;
}
