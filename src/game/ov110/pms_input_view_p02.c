/*
 * file:     pms_input_view_p02.c
 * unit:     yes
 * function: func_021B9608, func_021B9654, func_021B96C0
 * address:  0x021B9608
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C1E80 0x021C1E80 data a4
 *   func_02024148 0x02024148 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_02024150 0x02024150 thumb
 */
struct Blk37;
typedef unsigned short u16;

typedef struct {void *save;void *words;int counts[12];int starts[12];u16 values[1];} Object;

typedef struct {int (*fn)(Object *,const u16 *,unsigned int,u16 *); const u16 *data;unsigned int count;} Entry;

typedef unsigned char u8;

typedef unsigned int u32;

extern void *func_02024148(char *p);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern int func_02024150(void *);
void func_021B9608(Object *p);
u32 func_021B9654(u8 *p,const u16 *ids,u32 count,u16 *out);
u32 func_021B96C0(u8 *p,const u16 *ids,u32 count,u16 *out);
extern const Entry d_021C1E80[];

void func_021B9608(Object *p)
{
    int i;
    int n;
    i=0;
    n=0;
    for(;i<12;i++){
        p->starts[i]=n;
        p->counts[i]=d_021C1E80[i].fn(p,d_021C1E80[i].data,d_021C1E80[i].count,p->values+n);
        n+=p->counts[i];
    }
}

/*
 *   Verified EXACT in scratch b24148-r1.log:
 *   void *func_02024148(char *p){return *(void **)(p+8);}
 */
u32 func_021B9654(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    void *save;
    u32 n;
    u32 i;
    save=func_02024148(*(void **)p);
    n=0;
    for(i=0;i<count;i++){
        if(func_0200D064(save,ids[i])){
            u32 id=ids[i];
            p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
            *out++=id;
            n++;
        }
    }
    return n;
}

u32 func_021B96C0(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    u32 i;
    if(func_02024150(*(void **)p)){
        for(i=0;i<count;i++){
            u32 id= *ids;
            p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
            ids++;
            *out++=id;
        }
        return count;
    }
    return 0;
}
