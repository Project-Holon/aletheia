/*
 * function: func_021FC0C8
 * address: 0x021FC0C8
 * packet: pkt_ov186_021FC0C8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void func_021FC0C8(char *p,unsigned i)
{
    int *r=(int *)(p+8+i*12);
    switch(i){
    case 11: case 12:
        CLACT_ReleasePalette(r[2]);
        CLACT_ReleaseCharacter(r[1]);
        CLACT_ReleaseCellAnim(r[0]);
        break;
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 13:
        CLACT_ReleaseCharacter(r[1]);
        CLACT_ReleaseCellAnim(r[0]);
        break;
    case 4: case 5: break;
    }
    *(int *)(p+0xb0+i*4)=0;
}
