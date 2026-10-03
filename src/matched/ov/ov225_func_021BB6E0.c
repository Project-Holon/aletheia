/*
 * function: func_021BB6E0
 * address: 0x021BB6E0
 * packet: pkt_ov225_021BB6E0
 * status: EXACT
 * region: ov225
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * lever: u16 groups/items counts preserve target word spills/reloads; full callee bodies return ldrh values. Widened count locals compiled272B/191 concrete bytes; narrow counts compiled EXACT276B.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9C50 0x021B9C50 thumb ov225
 *   func_021B9C34 0x021B9C34 thumb ov225
 *   func_021B9C40 0x021B9C40 thumb ov225
 *   func_021B9BD4 0x021B9BD4 thumb ov225
 *   func_021B9C58 0x021B9C58 thumb ov225
 *   func_021B9C28 0x021B9C28 thumb ov225
 *   func_021BA65C 0x021BA65C thumb ov225
 *   func_021BB850 0x021BB850 thumb ov225
 *   d_021BC048 0x021BC048 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u16 func_021B9C50(char *);
extern u16 func_021B9C34(char *,int);
extern u16 func_021B9C40(char *,int,int);
extern u16 func_021B9BD4(char *,int);
extern int func_021B9C58(void *,int,void *);
extern u16 func_021B9C28(char *,int);
extern char *func_021BA65C(char *,char *);
extern void func_021BB850(void);
extern const char d_021BC048[];
char *func_021BB6E0(char *p,char *data)
{
    char *q;
    u16 groups,items;
    u16 i,j,valid;
    q=func_02030734(*(u16 *)(data+4),0x24,1,d_021BC048,0x5c);
    *(char **)q=p;
    *(u32 *)(p+4)=0;
    *(u16 *)(*(char **)q+8)=0;
    *(char **)(q+4)=data;
    *(u32 *)(q+8)=0;
    groups=func_021B9C50(*(char **)(data+0x2c));
    *(u16 *)(q+0xc)=0;
    *(char **)(q+0x10)=func_02030734(*(u16 *)(*(char **)(q+4)+4),groups*8,1,d_021BC048,0x71);
    for(i=0;i<groups;i++) {
        valid=0;
        items=func_021B9C34(*(char **)(*(char **)(q+4)+0x2c),i);
        for(j=0;j<items;j++) {
            int id;
            id=func_021B9C40(*(char **)(*(char **)(q+4)+0x2c),i,j);
            id=func_021B9BD4(*(char **)(*(char **)(q+4)+0x2c),id);
            if(func_021B9C58(*(void **)(*(char **)(q+4)+0x2c),id,*(void **)*(char **)(q+4))) valid++;
        }
        if(valid) {
            *(u16 *)(*(char **)(q+0x10)+*(u16 *)(q+0xc)*8)=i;
            *(u16 *)(*(char **)(q+0x10)+*(u16 *)(q+0xc)*8+2)=func_021B9C28(*(char **)(*(char **)(q+4)+0x2c),i);
            *(u32 *)(*(char **)(q+0x10)+*(u16 *)(q+0xc)*8+4)=0;
            *(u16 *)(q+0xc)+=1;
        }
    }
    *(u16 *)(q+0x14)=*(u16 *)*(char **)q;
    *(u16 *)(q+0x16)=*(u16 *)(*(char **)q+2);
    *(char **)(q+0x1c)=func_021BA65C(q+8,data);
    *(void **)(q+0x20)=func_020056A0((unsigned)func_021BB850,(unsigned)q,1);
    return q;
}
