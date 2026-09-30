/*
 * function: func_021C0554
 * address: 0x021C0554
 * packet: pkt_ov099_021C0554
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: an inline helper's enum temporary derives 0x274 independently at
 *   each call; the open p+(o+0x28) expression caches that offset and spills i/q.
 * symbols:
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 */
extern int func_021B97F4(char *);
extern int func_021BA858(char *);
extern void *func_021BE2A8(char *,int);
extern void func_021B9B64(char *);
extern int func_021C27E0(void *);
extern void func_021BAAB8(char *,int,int);
extern void func_021BA8EC(char *);
extern void func_021C18C8(char *,int,int);
extern void func_021C2408(char *);
extern void func_021B9AE0(char *,void *);
typedef enum { K24c=0x24c } Off;
static inline char *part(char *p,Off o) {
    Off t;
    t=o;
    t+=0x28;
    return p+t;
}
int func_021C0554(char *p,int ret) {
    Off o;
    int i;
    int r;
    void *q;
    o=K24c;
    i=func_021B97F4(part(p,o));
    r=func_021BA858(p);
    q=func_021BE2A8(p,i);
    func_021B9B64(part(p,o));
    if(r==-1)return ret;
    if(r==0){
        *(int *)(p+0x135c)=2;
        if(func_021C27E0(p+o)==func_021C27E0(*(void **)(p+8))){
            *(int *)(p+(o-0x80))=118;
        }else{
            if(func_021C27E0(*(void **)(p+8)))func_021BAAB8(p,73,0);
            else func_021BAAB8(p,72,0);
            *(int *)(p+0x1cc)=55;
        }
    } else {
        func_021BA8EC(p);
        func_021C18C8(p,1,2);
        *(int *)(p+(o-0x5c))=-1;
        func_021C2408(p);
        *(int *)(p+(o-0x80))=11;
        if(q)func_021B9AE0(part(p,o),q);
    }
    return ret;
}
