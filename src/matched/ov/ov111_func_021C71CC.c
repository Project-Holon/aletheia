/*
 * function: VIEWER_TEXT_FreeResources
 * address:  0x021C71CC
 * packet:   pkt_ov111_021C71CC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02030EAC  0x02030EAC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

struct Node;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *p);

void VIEWER_TEXT_FreeResources(Work *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        STRBUF_Delete(p->f2C[i]);
    }
    STRBUF_Delete(p->f28);
    WORDSET_DeleteStrbufED04(p->f24);
    MSGDATA_Delete(p->f20);
    func_02030EAC(p->fF4);
    ARC_TOOL_DeleteHandle(p->f0);
}
