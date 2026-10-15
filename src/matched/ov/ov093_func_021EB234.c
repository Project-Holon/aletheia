/*
 * function: BTLV_SCU_Delete
 * address:  0x021EB234
 * packet:   pkt_ov093_021EB234
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_FreeNamePlates  0x021EDBE8  thumb  ov093
 *   BTLV_SCU_ResetMonSlots  0x021ED988  thumb  ov093
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 pad0c[3];
    u32 f18;
    u32 pad1c[6];
    u32 f34;
    u32 f38;
    u32 f3c;
} Obj;

typedef unsigned char  u8;
extern void BTLV_SCU_FreeNamePlates(char *s);
extern void BTLV_SCU_ResetMonSlots(u8 *p);
struct Descriptor;
struct PrintSys;
struct U16Vec;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);

void BTLV_SCU_Delete(Obj *p)
{
    BTLV_SCU_FreeNamePlates((char *)p);
    BTLV_SCU_ResetMonSlots((u8 *)p);
    if (p->f08 != 0) {
        BMP_WIN_Delete((struct Descriptor *)p->f08);
        p->f08 = 0;
    }
    if (p->f00 != 0) {
        BMP_WIN_Delete((struct Descriptor *)p->f00);
        p->f00 = 0;
    }
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
    if (p->f18 != 0) {
        PRINTSYS_QUE_Delete((struct PrintSys *)p->f18);
        p->f18 = 0;
    }
    if (p->f3c != 0) {
        STRBUF_Delete((struct U16Vec *)p->f3c);
        p->f3c = 0;
    }
    if (p->f38 != 0) {
        STRBUF_Delete((struct U16Vec *)p->f38);
        p->f38 = 0;
    }
    STRBUF_Delete((struct U16Vec *)p->f34);
    func_020307B0(p);
}
