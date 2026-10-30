# Supported ROMs

The source builds these cartridges. Each one must be a legal dump of your own
cartridge, and it must match the SHA-1 below (the No-Intro entry). Every dump is
268,435,456 bytes.

Put the ROM in the repository root under the file name in the first column. ROMs are
never committed.

| File | Target | No-Intro name | Game code | SHA-1 |
|---|---|---|---|---|
| `black.nds` | `black` | Pokemon - Black Version (USA, Europe) (NDSi Enhanced) | IRBO | `26ad0b9967aa279c4a266ee69f52b9b2332399a5` |
| `white.nds` | `white` | Pokemon - White Version (USA, Europe) (NDSi Enhanced) | IRAO | `bc696a0dfb448c7b3a8a206f0f8214411a039208` |
| `black_fr.nds` | `black_fr` | Pokemon - Version Noire (France) (NDSi Enhanced) | IRBF | `a559da54839663d8f8f3f03382e5665a61873d22` |
| `white_fr.nds` | `white_fr` | Pokemon - Version Blanche (France) (NDSi Enhanced) | IRAF | `28f075915dd445cbfd902f1e1a94d5048b03a095` |
| `black_de.nds` | `black_de` | Pokemon - Schwarze Edition (Germany) (NDSi Enhanced) | IRBD | `f5688bd617be7e67a150732f42cfae6ae104b2cb` |
| `white_de.nds` | `white_de` | Pokemon - Weisse Edition (Germany) (NDSi Enhanced) | IRAD | `fb752b211351f8480e3e1949e11a1d7741f05f5a` |
| `black_it.nds` | `black_it` | Pokemon - Versione Nera (Italy) (NDSi Enhanced) | IRBI | `699f8c6a8390b5e30236b6c386bc3c4bd7bdc44e` |
| `white_it.nds` | `white_it` | Pokemon - Versione Bianca (Italy) (NDSi Enhanced) | IRAI | `2e33164d26236dd499f75d1de3123d85e822d502` |
| `black_es.nds` | `black_es` | Pokemon - Edicion Negra (Spain) (NDSi Enhanced) | IRBS | `68b55b82f5a033f9e9666c232f429e31ed658e54` |
| `white_es.nds` | `white_es` | Pokemon - Edicion Blanca (Spain) (NDSi Enhanced) | IRAS | `4cc963ca925409ff0f12f3c417d1cbe1094bf934` |

Each cartridge has one language. The USA/Europe cartridge is English only, and each
European language is its own cartridge.

`tools/targets.py` holds the same table for the tools. A tool takes the target from
`--target NAME` or the environment variable `ALETHEIA_TARGET` (`--version white` still
means `white`).

## Japanese (in progress)

The source builds 179 of the 181 regions of each Japanese cartridge byte-identical (the ARM9
module, the DSi block and 177 overlays). Two functions are still open, one in ov019 and one in
ov093 ([DEBT.tsv](DEBT.tsv)); `romlink.py --image-fallback` takes those two overlays from the dump.

| File | Target | No-Intro name | Game code | SHA-1 |
|---|---|---|---|---|
| `black_ja.nds` | `black_ja` | Pocket Monsters - Black (Japan) (NDSi Enhanced) | IRBJ | `4ce46933ab795fc8bfc94acb7a853206b0c20b60` |
| `white_ja.nds` | `white_ja` | Pocket Monsters - White (Japan) (NDSi Enhanced) | IRAJ | `e392548c1a59e4cafd7ba7a502770369410b2358` |

## Unpack and build a target

    python tools/ndsrom.py extract black_fr.nds -o extract_black_fr
    python tools/delink.py -e extract_black_fr -l build/black_fr/layout
    python tools/romlink.py --target black_fr --relink

The last command builds `build/rom/black_fr.nds` from `src/game` and compares its SHA-1 with
the table above. How the languages differ in the source: [LANGUAGES.md](LANGUAGES.md).

White keeps its older paths (`extract_white/`, `build/white/layout/`).
