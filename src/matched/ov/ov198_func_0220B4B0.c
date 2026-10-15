/*
 * function: B_PLIST_ANM_GetTileBuffer
 * address: 0x0220B4B0
 * packet: pkt_ov198_0220B4B0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
void *B_PLIST_ANM_GetTileBuffer(void *p,u32 kind,u32 i,int which)
{
 switch(kind){
 case 0:case 1:case 2:case 3:case 4:case 5:
  if(which==0) return (void *)((u32)p+0x1dc+i*0xc0);
  else return (void *)((u32)p+0x4dc+i*0xc0);
 case 6:return (void *)((u32)p+0xb74+i*0x32);
 case 7:return (void *)((u32)p+0xc3c+i*0x3fc);
 case 8:case 9:case 10:case 11:return (void *)((u32)p+0x7dc+i*0x82);
 case 12:return (void *)((u32)p+0x9e4+i*0x32);
 case 13:return (void *)((u32)p+0xaac+i*0x32);
 case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:case 24:case 25:case 26:
  return (void *)((u32)p+0x1830+i*0xc0);
 case 27:return (void *)((u32)p+0x1b30+i*0x104);
 case 28:case 29:case 30:case 31:return (void *)((u32)p+0x1e3c+i*0x14);
 default:return 0;
 }
}
