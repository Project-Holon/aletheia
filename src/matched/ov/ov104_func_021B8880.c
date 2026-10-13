/*
 * function: IRC_RHYTHM_CalcSyncScore
 * address: 0x021B8880
 * packet: pkt_ov104_021B8880
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Direct word indexing retains the second stack record's base across the call.
 * symbols:
 *   IRC_RHYTHM_GetPartnerRecord 0x021B87F4 thumb ov104
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int words[33]; } Block;
extern void IRC_RHYTHM_GetPartnerRecord(u8 *, Block *);
int IRC_RHYTHM_CalcSyncScore(u8 *p) {
 Block a; Block b; int d; u32 score, sum; int i; Block *bp;
 a=*(Block *)(p+0x814);
 bp=&b;
 IRC_RHYTHM_GetPartnerRecord(p+0xe0,bp);
 d=a.words[(*(u16 *)((u8 *)&a+120)-1)*2]-a.words[0]
  -(b.words[(*(u16 *)((u8 *)&b+120)-1)*2]-b.words[0]);
 if(d<0) d=-d;
 if(d==0) score=100;
 else if((u32)d<500) score=90;
 else if((u32)d<1000) score=80;
 else if((u32)d<3000) score=70;
 else if((u32)d<5000) score=60;
 else if((u32)d<10000) score=50;
 else if((u32)d<15000) score=40;
 else if((u32)d<20000) score=30;
 else if((u32)d<25000) score=20;
 else if((u32)d<30000) score=10;
 sum=0;
 for(i=1;i<10;i++) {
  d=*(int *)((u32)&a+i*8+4)-*(int *)((u32)&b+i*8+4);
  if(d<0) d=-d;
  if(d==0) sum+=100;
  else if((u32)d<50) sum+=90;
  else if((u32)d<100) sum+=80;
  else if((u32)d<200) sum+=70;
  else if((u32)d<300) sum+=60;
  else if((u32)d<400) sum+=50;
  else if((u32)d<500) sum+=40;
  else if((u32)d<600) sum+=30;
  else if((u32)d<1000) sum+=20;
  else if((u32)d<15000) sum+=10;
 }
 return (u8)((score+sum/9)/2);
}
