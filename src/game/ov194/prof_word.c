/*
 * file:     prof_word.c
 * unit:     yes
 * function: PROF_WORD_Create, PROF_WORD_Delete, PROF_WORD_FindMatch, PROF_WORD_CompareChunks, PROF_WORD_MatchWord, PROF_WORD_CheckDigitCount
 * address:  0x021F5304
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Zeroes a 0x20-entry u16 buffer (aggregate initialiser gives the
 * post-decrement loop), has MI_CpuCopy8 fill it from the caller's source, then
 * counts wide/ASCII digit code units: 1 when more than four.  Initialising c
 * at its declaration fixes the register of n.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadMemberWithSize 0x0204A298 arm
 *   GF_STANDARD_ShuffleEx 0x0203F37C arm
 *   d_021F57B8 0x021F57B8 data a1
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
typedef struct { unsigned data[7], size[7]; } Resources;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern int ARC_UTIL_LoadMemberWithSize(int, int, int, int, unsigned *);
extern void GF_STANDARD_ShuffleEx(void *p, unsigned int size, unsigned int seed);
extern u32 func_020307B0(void *p);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern u16 STRBUF_GetEosChar(void);
Resources *PROF_WORD_Create(unsigned short heap);
void PROF_WORD_Delete(u8 *p);
int PROF_WORD_FindMatch(const u32 *cache,const void *input,u16 heap);
int PROF_WORD_CompareChunks(const u16 *a, u32 b, u32 c, const u16 *d, u32 n);
int PROF_WORD_MatchWord(const u16 *a,const u16 *b);
int PROF_WORD_CheckDigitCount(void *src, int n, int a2);
extern const char d_021F57B8[];


/*
 * Match levers: u16 heap, counter declared first, zero set before size-base
 * assignment; the int heap and later zero caused the recorded diffs.
 */
Resources *PROF_WORD_Create(unsigned short heap)
{
    int i;
    Resources *p;
    unsigned *sizes;
    p = func_02030734(heap, 0x38, 1, d_021F57B8, 0x38);
    sizes = (unsigned *)p;
    i = 0;
    sizes = p->size;
    for (; i < 7; i++) {
        p->data[i] = ARC_UTIL_LoadMemberWithSize(0xDD, i, 0, heap, &sizes[i]);
        GF_STANDARD_ShuffleEx((void *)p->data[i], p->size[i], 0x72012891);
    }
    return p;
}



/*
 * Addresses are Black-image addresses.
 */
void PROF_WORD_Delete(u8 *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        func_020307B0((void *)(*(u32 *)(p + i * 4)));
    }
    func_020307B0((void *)((u32)p));
}


int PROF_WORD_FindMatch(const u32 *cache,const void *input,u16 heap)
{
    u16 buf[32]={0};
    u32 size;
    int i,result;
    u32 data;
    MI_CpuCopy8(input,buf,64);
    for(i=0;i<32;i++) {
        u32 c=buf[i];
        if(c>=0x30a1 && c<=0x30f4) buf[i]=c-0x60;
        else if(c>=0x61 && c<=0x7a) buf[i]=c-0x20;
        else if(c>=0xff41 && c<=0xff5a) buf[i]=c-0xff00;
        else if(c>=0xff21 && c<=0xff3a) buf[i]=c-0xfee0;
        else if(c>=0xe0 && c<=0xfe) buf[i]=c-0x20;
    }
    for(i=0;i<7;i++) {
        if(cache==0) {
            data=ARC_UTIL_LoadMemberWithSize(0xdd,i,0,heap,&size);
            GF_STANDARD_ShuffleEx((void *)data,size,0x72012891);
        } else {data=cache[i];size=cache[i+7];}
        { u32 currentHeap=heap; result=PROF_WORD_CompareChunks(buf,i,currentHeap,(const u16 *)data,size); }
        if(cache==0) func_020307B0((void *)data);
        if(result==1) break;
    }
    return result;
}


int PROF_WORD_CompareChunks(const u16 *a, u32 b, u32 c, const u16 *d, u32 n)
{
    int r;
    int i;
    int cnt = (n << 10) >> 16;
    for (i = 0; i < cnt; i++) {
        r = PROF_WORD_MatchWord(a, d + i * 32);
        if (r == 1) break;
    }
    return r;
}


int PROF_WORD_MatchWord(const u16 *a,const u16 *b) {int i;for(i=0;i<32;i++){if(a[i]!=b[i])return 0;if(a[i]==STRBUF_GetEosChar() && b[i]==STRBUF_GetEosChar())return 1;}return 0;}


int PROF_WORD_CheckDigitCount(void *src, int n, int a2)
{
    u16 buf[0x20] = {0};
    int j, c = 0;

    MI_CpuCopy8(src, buf, n * 2);
    for (j = 0; j < 0x20; j++) {
        u16 v = buf[j];

        if ((v >= 0x30 && v <= 0x39) || (v >= 0xFF10 && v <= 0xFF19))
            c++;
        if (c > 4)
            return 1;
    }
    return 0;
}
