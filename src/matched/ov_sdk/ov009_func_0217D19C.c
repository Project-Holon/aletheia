/*
 * function: func_0217D19C
 * address:  0x0217D19C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gsDebugVaList: the filtering dispatcher behind gsDebugFormat
 * (func_0217D254).  Lazily initialise the debug lock, take it, test the
 * category/type level byte and dispatch to the registered callback (or the
 * default va_list printer), then release the lock.
 *
 * The callback and the init flag are one object at 0x021AD000 (the flag is
 * read as [base,#4]); declaring them as a struct keeps that single pool
 * relocation.  The level table at 0x021AD020 is indexed [cat][type] with a
 * 5-byte row stride.
 *
 * symbols:
 *   gsiInitializeCriticalSection  0x0217F0FC  arm  ov009
 *   gsiEnterCriticalSection  0x0217F108  arm  ov009
 *   gsiLeaveCriticalSection  0x0217F114  arm  ov009
 *   func_0217D188  0x0217D188  arm  ov009
 *   g_021AD000     0x021AD000  data
 *   g_021AD008     0x021AD008  data
 *   g_021AD020     0x021AD020  data
 */

typedef char *va_list;

typedef struct {
    void (*callback)(int, int, int, const char *, va_list);
    int initialized;
} GSIDebugState;

extern void gsiInitializeCriticalSection(void *mutex);
extern void gsiEnterCriticalSection(void *mutex);
extern void gsiLeaveCriticalSection(void *mutex);
extern void func_0217D188(int a, int b, int c, int d, int e);
extern GSIDebugState g_021AD000;
extern int g_021AD008[];
extern unsigned char g_021AD020[][5];

void func_0217D19C(int cat, int type, int level, const char *fmt, va_list args)
{
    unsigned char enabled;

    if (g_021AD000.initialized == 0) {
        g_021AD000.initialized = 1;
        gsiInitializeCriticalSection(g_021AD008);
    }
    gsiEnterCriticalSection(g_021AD008);
    enabled = g_021AD020[cat][type];
    if (enabled & level) {
        if (g_021AD000.callback != 0)
            g_021AD000.callback(cat, type, level, fmt, args);
        else
            func_0217D188(cat, type, level, (int)fmt, (int)args);
    }
    gsiLeaveCriticalSection(g_021AD008);
}
