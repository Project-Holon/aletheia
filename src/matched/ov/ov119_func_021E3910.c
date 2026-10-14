/*
 * function: POKETRADE_3D_DrawCubeFace
 * address: 0x021E3910
 * packet: pkt_ov119_021E3910
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 third argument places its spill before hardware writes; caller supplies u16.
 * volatile: hardware command stores 021E391C..021E3A22, 04000440..04000504
 * symbols:
 *   func_0207D84C 0x0207D84C arm
 *   func_0207D810 0x0207D810 arm
 *   POKETRADE_3D_SetToonEdgeColors 0x021E38D8 thumb ov119
 *   POKETRADE_3D_SetCubeTexCoord 0x021E3744 thumb ov119
 *   POKETRADE_3D_SetCubeNormal 0x021E3730 thumb ov119
 *   POKETRADE_3D_EmitCubeVertex 0x021E3700 thumb ov119
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   d_021E8144 0x021E8144 data ov119 a4
 */
typedef unsigned long u32;
typedef unsigned short u16;
typedef short s16;
typedef long fx32;
extern void func_0207D84C(fx32,fx32);
extern void func_0207D810(fx32,fx32);
extern void POKETRADE_3D_SetToonEdgeColors(int,int);
extern void POKETRADE_3D_SetCubeTexCoord(int);
extern void POKETRADE_3D_SetCubeNormal(int);
extern void POKETRADE_3D_EmitCubeVertex(int);
extern const s16 FX_SinCosTable_[];
extern u16 d_021E8144[];
#define REG(a) (*(volatile u32 *)(a))
void POKETRADE_3D_DrawCubeFace(int z,int index,u16 a,int b)
{
    REG(0x04000444)=0;
    REG(0x04000440)=1;
    func_0207D84C(FX_SinCosTable_[(b>>4)*2],FX_SinCosTable_[(b>>4)*2+1]);
    REG(0x04000444)=0;
    func_0207D84C(FX_SinCosTable_[(a>>4)*2],FX_SinCosTable_[(a>>4)*2+1]);
    REG(0x04000470)=0;
    REG(0x04000470)=0;
    REG(0x04000470)=z;
    func_0207D84C(FX_SinCosTable_[(d_021E8144[0]>>4)*2],FX_SinCosTable_[(d_021E8144[0]>>4)*2+1]);
    func_0207D810(FX_SinCosTable_[(d_021E8144[1]>>4)*2],FX_SinCosTable_[(d_021E8144[1]>>4)*2+1]);
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x04000440)=3;
    REG(0x04000454)=0;
    REG(0x04000440)=2;
    POKETRADE_3D_SetToonEdgeColors(1,1);
    REG(0x040004a8)=0x4d200000|(((u32)index*512+0x3000)>>3);
    REG(0x040004ac)=512;
    REG(0x040004a4)=0x1f0041|((u32)index<<24);
    REG(0x04000500)=1;
    POKETRADE_3D_SetCubeTexCoord(1); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(2);
    POKETRADE_3D_SetCubeTexCoord(0); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(0);
    POKETRADE_3D_SetCubeTexCoord(2); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(4);
    POKETRADE_3D_SetCubeTexCoord(3); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(6);
    REG(0x04000504)=0;
    REG(0x04000448)=1;
    REG(0x04000448)=1;
}
