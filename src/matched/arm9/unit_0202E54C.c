/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202E54C
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: CODEIN_PARAM_Delete
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *
 * A destructor: release the one owned handle at offset 0x20, then free
 * the object.
 *
 * Matched as a one-function unit because the two bytes of `00 00` at
 * 0x0202E55E are the linker's inter-section fill before 0x0202E560.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E54C.c \
 *       --addr 0x0202E54C --thumb
 */

typedef unsigned char u8;

struct Obj0202E54C {
    u8    pad[0x20];
    void *unk20;
};

struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void CODEIN_PARAM_Delete(struct Obj0202E54C *p)
{
    func_02045808(p->unk20);
    func_020307B0(p);
}
