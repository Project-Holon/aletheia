/*
 * file:     unit_021B23E0_p06.c
 * unit:     yes
 * function: func_021B2958, func_021B29A4
 * address:  0x021B2958
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   d_021B60D8 0x021B60D8 data ov013 a4
 *   d_021B3B40 0x021B3B40 data ov013 a1
 *   d_021B3B84 0x021B3B84 data ov013 a1
 */
typedef struct N {
    int a;
    int b;
    int c;
    int kind;
    int e;
    struct N *next;
} N;

typedef struct {
    int x;
    N *head;
} G;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

int func_021B2958(N *p);
int func_021B29A4(int *obj,const u8 *q);
extern G d_021B4BE0;
extern int d_021B60D8[];
extern s8 d_021B3B40[],d_021B3B84[];


int func_021B2958(N *p)
{
    N *n;

    n = d_021B4BE0.head;
    while (n) {
        if (n->a != 0 && n->kind == 2) {
            if (p != n)
                return 0;
        }
        n = n->next;
    }
    return 1;
}

static inline s8 lookup(u32 t,int row,u32 col) { return *(s8 *)(row*11+t+col); }

/*
 * lever: Calling the indexed inline in each table-selection arm restores the MLA register and independent -1/-2 constants.
 * checks: Per-arm inline lookup is EXACT; one data table in each arm preserves the original dispatch.
 */
int func_021B29A4(int *obj,const u8 *q) {
 u32 i; int v; u32 t;
 i=q[6]; if(q[4]==0)i+=5; if(i>=11)i=-1; if((int)i<0)return -1;
 if(d_021B60D8[4]==1) v=lookup((u32)d_021B3B40,obj[3],i);
 else v=lookup((u32)d_021B3B84,obj[3],i);
 if(v==-1)return 1; if(v==-2)return 0; obj[3]=v; return 1;
}
