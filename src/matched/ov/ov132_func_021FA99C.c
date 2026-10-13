/*
 * function: func_021FA99C
 * address: 0x021FA99C
 * packet: pkt_ov132_021FA99C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: copies a tile sheet into VRAM in 4-byte pieces (block x line x column).
 * CLACT_GetCharacterVramAddress returns a pointer (the matched ov119 021E6E7C and ov131 021DBCF4 use it so),
 * which removed the old prototype blocker. Levers: locals declared in the order of the
 * frame slots (dst, block, height, line, y, x, src), u16 slot (puts its entry spill first),
 * u8 height, case 50 reads x = y, and y = 0 written after the blob call (literal 0 in it).
 * symbols:
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E804 0x0207E804 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int ARC_UTIL_LoadMember(int,int,int,int);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
extern void DWCi_ScreenDC_FlushRange(void *,u32);
extern void func_0207E5D0(const void *,u32,u32);
extern void func_0207E804(const void *,void *,u32);
extern u32 func_020307B0(void *p);
void func_021FA99C(u8 *p,u16 slot,int resource,u32 type)
{
    int blob;
    u32 charSize,palSize;
    u8 *dst;
    u8 block;
    u8 height;
    u8 line;
    u32 y;
    u32 x;
    u8 *src;
    u8 *tex;
    u32 palOffset;
    u8 col;
    blob=ARC_UTIL_LoadMember(45,resource,0,*(u16 *)p);
    y=0;
    tex=NNS_G3dGetTex((unsigned char *)blob);
    src=tex+*(u32 *)(tex+20);
    charSize=*(u16 *)(tex+12)*8;
    palOffset=*(u32 *)(tex+0x38);
    palSize=*(u16 *)(tex+0x30)*8;
    dst=(u8 *)CLACT_GetCharacterVramAddress(*(u32 *)(p+0x28),1);
    dst+=(slot<<11);
    DWCi_ScreenDC_FlushRange(tex+palOffset,palSize);
    func_0207E5D0(tex+palOffset,slot*32,palSize);
    DWCi_ScreenDC_FlushRange(src,charSize);
    switch(type) {
    case 34: x=2; y=2; type=4; height=4; break;
    case 35: x=2; type=4; height=8; break;
    case 50: x=y; y=2; type=8; height=4; break;
    default: x=2; y=2; type=4; height=4; break;
    }
    for(block=0;block<height;block++) {
        for(line=0;line<8;line++) {
            for(col=0;col<type;col++) {
                func_0207E804(src+(col*4+(block*32*type+line*type*4)),dst+(line*4+((col+x)*32+((block+y)*256))),4);
            }
        }
    }
    func_020307B0((void *)blob);
}
