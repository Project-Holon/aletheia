/*
 * function: func_021B8B9C
 * address: 0x021B8B9C
 * packet: pkt_ov106_021B8B9C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 sole callers 0x0200A930 and 0x0200A908 lack a matched or label witness.
 *   Verified separately with fixed one flags (EXACT, 16 and 38 bytes):
 *   typedef struct { u8 pad[0x348]; u32 f:8,rest:24; } Rec;
 *   u8 func_0200A930(const Rec *p) { return p->f; }
 *   typedef struct {u8 pad[24];u16 n;u8 a;u8 b:6,c:1,d:1;} Entry;
 *   void func_0200A908(const Entry *p,u32 i,u16 *n,u8 *a,u8 *b,u8 *c) {
 *     *n=p[i].n; *a=p[i].a; *b=p[i].b; *c=p[i].c;
 *   }
 * 2026-10-05: byte-identical; the wildcard is arm9 func_0200A930 (new matched/arm9 file, EXACT, this lane, bitfield read); needs its shard.
 *
 * 2026-10-05 (D9 lane 02): the last wildcard (arm9 func_0200A908) now has its witness: src/matched/arm9/func_0200A908.c (EXACT, 38 bytes, the Entry reader above).
 *   Only its shard is missing, so this stays MATCH until the integrator builds it.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200A930 0x0200A930 thumb
 *   func_0200A8E4 0x0200A8E4 thumb
 *   func_0200A908 0x0200A908 thumb
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetString 0x02045924 arm
 *   d_021B9680 0x021B9680 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
 void *text;
 u32 id:7, value:10, tag:8, seq:7;
 u16 number;
 u8 a,b,c,active,pad[2];
} Item;
extern const char d_021B9680[];
typedef signed int     s32;
struct Big;
struct Entry;
struct Rec;
struct Strbuf;
struct U16Vec;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200A8A0(void *);
extern s32 func_0200A8AC(struct Rec *r);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32);
extern u8 func_0200A930(char *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u8 func_0200A8D0(struct Rec *r, u32 index);
extern u16 func_0200A8E4(struct Rec *r, u32 index);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern void func_0200A908(void *,u32,u16 *,u8 *,u8 *,u8 *);
void *func_021B8B9C(void *sys,u16 heap) {
 void *src; u16 count; u8 *out; Item *item; u32 i; u8 prev,seq,active;
 src=func_0200A8A0(GAME_DATA_GetSaveControl(sys));
 count=func_0200A8AC(src);
 out=func_02030734(heap,count*16+4,0,d_021B9680,2724);
 MI_CpuFill8(out,0,count*16+4);
 *(u32 *)out=count;
 if(count) {
  prev=128; seq=0; active=func_0200A930(src);
  for(i=0;i<*(u32 *)out;i++) {
   item=(Item *)(out+4+i*16);
   item->text=STRBUF_Create(8,heap);
   STRBUF_SetString(item->text,(const u16 *)func_0200A8C8(src,i));
   item->id=func_0200A8D0(src,i);
   item->value=func_0200A8E4(src,i);
   if(item->id<prev) item->seq=i+1;
   else if(item->id==prev) item->seq=seq;
   {
    u8 flag; int v;
    flag=func_0200A8F8(src,i);
    if(active==i) {
     v=flag==0;
     item->tag=5*(v+1);
     item->active=1;
    } else if(item->seq==1) {
     v=0; if(flag==0) v=5; item->tag=v+2;
    } else if(item->seq==2) {
     v=0; if(flag==0) v=5; item->tag=v+3;
    } else if(item->seq==3) {
     v=0; if(flag==0) v=5; item->tag=v+4;
    } else {
     v=0; if(flag==0) v=5; item->tag=v+1;
    }
   }
   func_0200A908(src,i,&item->number,&item->a,&item->b,&item->c);
   prev=item->id; seq=item->seq;
  }
 }
 return out;
}
