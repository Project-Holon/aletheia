/*
 * function: func_021D7550
 * address: 0x021D7550
 * packet: pkt_ov116_021D7550
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: entry r0/r1 remain arguments to 7278,7324 and 81EC through dispatch.
 * symbols:
 *   func_021D69A8 0x021D69A8 thumb ov116
 *   func_021D69C0 0x021D69C0 thumb ov116
 *   func_021D69EC 0x021D69EC thumb ov116
 *   func_021D6A10 0x021D6A10 thumb ov116
 *   func_021D6A40 0x021D6A40 thumb ov116
 *   func_021D6A44 0x021D6A44 thumb ov116
 *   func_021D6A48 0x021D6A48 thumb ov116
 *   func_021D6A4C 0x021D6A4C thumb ov116
 *   func_021D6A5C 0x021D6A5C thumb ov116
 *   func_021D6AF0 0x021D6AF0 thumb ov116
 *   func_021D6B30 0x021D6B30 thumb ov116
 *   func_021D7278 0x021D7278 thumb ov116
 *   func_021D730C 0x021D730C thumb ov116
 *   func_021D7324 0x021D7324 thumb ov116
 *   func_021D7B70 0x021D7B70 thumb ov116
 *   func_021D7C58 0x021D7C58 thumb ov116
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D8118 0x021D8118 thumb ov116
 *   func_021D8134 0x021D8134 thumb ov116
 *   func_021D8168 0x021D8168 thumb ov116
 *   func_021D8190 0x021D8190 thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 *   func_021D81D0 0x021D81D0 thumb ov116
 *   func_021D81EC 0x021D81EC thumb ov116
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02167ED8 0x02167ED8 arm ov009
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0200DC08(void *);
extern void func_021D69A8(u8 *,u8 *,u16),func_021D69EC(u8 *,u8 *,u16);
extern int func_021D69C0(u8 *,u8 *),func_021D6A10(u8 *,u8 *);
extern u16 func_021D6A40(u8 *),func_021D6A44(u8 *),func_021D6A48(u8 *);
extern void *func_021D6A4C(u8 *);
extern void func_021D6A5C(u8 *),func_021D6AF0(u8 *,void *),func_021D6B30(u8 *,void *);
extern void func_021D7278(u8 *,int),func_021D730C(void *);
extern u32 func_021D7324(u8 *);
extern void func_021D7B70(u8 *,u32),func_021D7C58(u8 *),func_021D8010(void *,u32);
extern int func_021D80CC(void *),func_021D8168(void *),func_021D81EC(u8 *),func_0204E804(void);
extern void func_021D8118(u8 *,int,int,void *),func_021D8134(void *),func_021D8190(void *),func_021D81B4(void *),func_021D81D0(u8 *),func_0204E720(int,int,int,int);
extern int func_02167ED8(void *date, void *time);
extern int func_0200DDD0(void *,u8,u8,void *);
int func_021D7550(u8 *p,int heap)
{
    int v,box;
    u32 n;
    u8 extra[12];
    u8 record[16];
    switch(*(u32 *)(p+0xb6c)) {
    case 0: func_021D69A8(p+0xb74,p+0x182c,func_0200DC08(*(void **)(p+0x1858))); ++*(u32 *)(p+0xb6c); break;
    case 1: if(func_021D69C0(p+0xb74,p+0x182c)!=0) ++*(u32 *)(p+0xb6c); break;
    case 2:
        func_021D81B4(p+4); v=func_021D6A48(p+0xb74);
        func_021D8118(p+4,0,v,func_021D6A4C(p+0xb74)); func_021D8010(p+4,0); ++*(u32 *)(p+0xb6c); break;
    case 3: if(func_021D80CC(p+4)!=0) ++*(u32 *)(p+0xb6c); break;
    case 4: func_0204E720(3,0,16,1); ++*(u32 *)(p+0xb6c); break;
    case 5: if(func_0204E804()==0) { func_021D7C58(p+4); ++*(u32 *)(p+0xb6c); } break;
    case 6: func_021D7278(p,heap); ++*(u32 *)(p+0xb6c); break;
    case 7: *(u32 *)(p+0xb70)=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720(3,16,0,1); ++*(u32 *)(p+0xb6c); break;
    case 8:
        if(func_0204E804()==0) {
            box=func_021D6A40(p+0xb74); n=*(u32 *)(p+0xb70); v=func_021D6A48(p+0xb74);
            func_02167ED8(record,extra);
            if(n<1 || n>(u32)v) { *(u32 *)(p+0xb6c)=16; break; }
            if(func_0200DDD0(*(void **)(p+0x1854),box,n,record)!=0) { *(u32 *)(p+0xb6c)=14; break; }
            func_021D69EC(p+0xb74,p+0x182c,*(u32 *)(p+0xb70));
            v=func_021D6A44(p+0xb74); func_021D8118(p+4,0,v,func_021D6A4C(p+0xb74));
            func_021D8118(p+4,1,func_021D6A40(p+0xb74),(void *)2); func_021D8010(p+4,1); func_021D8190(p+4); ++*(u32 *)(p+0xb6c);
        } break;
    case 9: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++*(u32 *)(p+0xb6c); break;
    case 10: func_021D6A5C(p+0xb74); func_021D6AF0(p+0xb74,*(void **)(p+0x1854)); func_021D6B30(p+0xb74,*(void **)(p+0x1854)); func_021D81D0(p); ++*(u32 *)(p+0xb6c); break;
    case 11: if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,3); ++*(u32 *)(p+0xb6c); } break;
    case 12: if(func_021D80CC(p+4)!=0) ++*(u32 *)(p+0xb6c); break;
    case 13: return 1;
    case 14: func_021D8010(p+4,2); ++*(u32 *)(p+0xb6c); break;
    case 15: if(func_021D80CC(p+4)!=0) *(u32 *)(p+0xb6c)=2; break;
    case 16: func_021D8010(p+4,4); ++*(u32 *)(p+0xb6c); break;
    case 17: if(func_021D80CC(p+4)!=0) ++*(u32 *)(p+0xb6c); break;
    case 18: func_021D8134(p+4); ++*(u32 *)(p+0xb6c); break;
    case 19: v=func_021D8168(p+4); if(v==0) return 2; if(v==-2) *(u32 *)(p+0xb6c)=2; break;
    }
    return 0;
}
