/*
 * function: FIELD_WFBC_FreeResources
 * address:  0x02193C80
 * packet:   pkt_ov021_02193C80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable  0x0218683C  thumb  ov020
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct X {
    u32 f00;
    void *f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    void *f14;
    u8  pad18[0x100];
    u32 f118;
} X;

extern void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(void *p);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(void **p);

void FIELD_WFBC_FreeResources(X *x)
{
    if (x->f0c != 0) {
        FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable((void *)x->f118);
        func_020307B0(x->f14);
        ARC_TOOL_DeleteHandle(x->f10);
        FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)x->f0c);
        func_020307B0(x->f04);
        x->f0c = 0;
        x->f04 = 0;
        x->f10 = 0;
        x->f14 = 0;
        x->f118 = 0;
    }
}
