/*
 * unit: yes
 * function: STA_ACT_OBJ_FreeEntry, STA_ACT_OBJ_SetEntryTarget, STA_ACT_OBJ_GetEntryTarget
 * address: 0x021F6B80
 * packet: pkt_ov112_021F6B80
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 */
typedef unsigned int u32;
extern void BILLBOARD_FreeElem(void *, u32);
typedef unsigned char  u8;
extern void BILLBOARD_DeleteImage(u8 *a0, int i);
void STA_ACT_OBJ_FreeEntry(u32 *a, u32 *b)
{
    BILLBOARD_FreeElem((void *)a[1], b[6]);
    BILLBOARD_DeleteImage((void *)a[1], b[5]);
    b[0]=0;
}
void STA_ACT_OBJ_SetEntryTarget(void *a, u32 *b, u32 *c)
{
    b[2]=c[0]; b[3]=c[1]; b[4]=c[2]; b[1]=1;
}
void STA_ACT_OBJ_GetEntryTarget(void *a, u32 *b, u32 *c)
{
    c[0]=b[2]; c[1]=b[3]; c[2]=b[4];
}
