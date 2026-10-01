/*
 * function: func_0217B2E4
 * address: 0x0217B2E4
 * packet: pkt_ov176_0217B2E4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02045B38 0x02045B38 arm
 *   d_0217E5E4 0x0217E5E4 data a1
 *   func_0217B380 0x0217B380 thumb ov176
 *   func_021E8A3C 0x021E8A3C thumb ov177
 */
typedef struct Data { unsigned words[8]; } Data;
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02045B38(int,int,int,unsigned);
extern const char d_0217E5E4[];
extern void func_0217B380(int,int,int *);
extern void *func_021E8A3C(void *,void (*)(int,int,int *),unsigned);
void *func_0217B2E4(const Data *src,unsigned heap)
{
    char *p;
    p=func_02030734(heap,0x3c,0,d_0217E5E4,0xaf);
    func_02082BCC(p,0,0x3c);
    *(Data *)(p+0x14)=*src;
    *(unsigned short *)(p+0x34)=heap;
    *(void **)(p+0xc)=func_02045B38(0,3,0x9e,heap);
    *(void **)p=func_021E8A3C(p,func_0217B380,heap);
    return p;
}
