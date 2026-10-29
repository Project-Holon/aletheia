#!/usr/bin/env python3
"""
targets.py -- the ROMs the source builds, and where each one's files live.

A target is one cartridge: a version (Black or White) and a language.  Pokemon Black USA/Europe
(English) is the reference: its layout is layout/ and its extract is extract/.  Every other
target is linked from the same src/game files with VERSION and LANGUAGE set (src/game/version.h)
and its addresses mapped from Black's (tools/white_map.py).

The tools take the target from --target NAME or the environment variable ALETHEIA_TARGET.
The older --version white and ALETHEIA_VERSION=white still mean the target "white".

Paths of a target T other than black:
    T.nds                 the user's ROM in the repo root (never committed)
    extract_T/            tools/ndsrom.py extract of it (gitignored)
    build/T/layout/       tools/delink.py of the extract
    build/T/              maps and other caches
White keeps its older names (extract_white/, build/white/).

Language ids are the game's own (MYSTATUS language field): 1 Japanese, 2 English, 3 French,
4 Italian, 5 German, 7 Spanish.  Stdlib only.
"""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

VERSION_IDS = {"black": 1, "white": 2}           # src/game/version.h VERSION_BLACK, VERSION_WHITE
LANGUAGE_IDS = {"ja": 1, "en": 2, "fr": 3, "it": 4, "de": 5, "es": 7}

# name: (version, language, game code, No-Intro name, SHA-1 of the verified dump)
TARGETS = {
    "black":    ("black", "en", "IRBO", "Pokemon - Black Version (USA, Europe) (NDSi Enhanced)",
                 "26ad0b9967aa279c4a266ee69f52b9b2332399a5"),
    "white":    ("white", "en", "IRAO", "Pokemon - White Version (USA, Europe) (NDSi Enhanced)",
                 "bc696a0dfb448c7b3a8a206f0f8214411a039208"),
    "black_fr": ("black", "fr", "IRBF", "Pokemon - Version Noire (France) (NDSi Enhanced)",
                 "a559da54839663d8f8f3f03382e5665a61873d22"),
    "white_fr": ("white", "fr", "IRAF", "Pokemon - Version Blanche (France) (NDSi Enhanced)",
                 "28f075915dd445cbfd902f1e1a94d5048b03a095"),
    "black_de": ("black", "de", "IRBD", "Pokemon - Schwarze Edition (Germany) (NDSi Enhanced)",
                 "f5688bd617be7e67a150732f42cfae6ae104b2cb"),
    "white_de": ("white", "de", "IRAD", "Pokemon - Weisse Edition (Germany) (NDSi Enhanced)",
                 "fb752b211351f8480e3e1949e11a1d7741f05f5a"),
    "black_it": ("black", "it", "IRBI", "Pokemon - Versione Nera (Italy) (NDSi Enhanced)",
                 "699f8c6a8390b5e30236b6c386bc3c4bd7bdc44e"),
    "white_it": ("white", "it", "IRAI", "Pokemon - Versione Bianca (Italy) (NDSi Enhanced)",
                 "2e33164d26236dd499f75d1de3123d85e822d502"),
    "black_es": ("black", "es", "IRBS", "Pokemon - Edicion Negra (Spain) (NDSi Enhanced)",
                 "68b55b82f5a033f9e9666c232f429e31ed658e54"),
    "white_es": ("white", "es", "IRAS", "Pokemon - Edicion Blanca (Spain) (NDSi Enhanced)",
                 "4cc963ca925409ff0f12f3c417d1cbe1094bf934"),
    "black_ja": ("black", "ja", "IRBJ", "Pocket Monsters - Black (Japan) (NDSi Enhanced)",
                 "4ce46933ab795fc8bfc94acb7a853206b0c20b60"),
    "white_ja": ("white", "ja", "IRAJ", "Pocket Monsters - White (Japan) (NDSi Enhanced)",
                 "e392548c1a59e4cafd7ba7a502770369410b2358"),
}

GAMECODES = tuple(t[2].encode() for t in TARGETS.values())


def current(default="black"):
    """The target named by ALETHEIA_TARGET, else ALETHEIA_VERSION (black or white), else default."""
    t = os.environ.get("ALETHEIA_TARGET") or os.environ.get("ALETHEIA_VERSION") or default
    t = t.lower()
    if t not in TARGETS:
        raise SystemExit("unknown target %r (known: %s)" % (t, ", ".join(TARGETS)))
    return t


def version(t):
    return TARGETS[t][0]


def language(t):
    return TARGETS[t][1]


def is_reference(t):
    return t == "black"


def defines(t):
    """mwcc -d flags for a target (none for the reference, so Black's command lines stay as they were)."""
    out = []
    if version(t) != "black":
        out += ["-d", "VERSION=%d" % VERSION_IDS[version(t)]]
    if language(t) != "en":
        out += ["-d", "LANGUAGE=%d" % LANGUAGE_IDS[language(t)]]
    return out


def rom_path(t):
    return os.path.join(ROOT, "black.nds" if t == "black" else t + ".nds")


def extract_dir(t):
    return os.path.join(ROOT, "extract" if t == "black" else "extract_" + t)


def build_dir(t):
    """build/T/ (Black has none: its caches are the plain build/ paths)."""
    return os.path.join(ROOT, "build", t)


def layout_dir(t):
    return os.path.join(ROOT, "layout") if t == "black" else os.path.join(build_dir(t), "layout")


def suffix(t):
    """Output-name suffix: '' for Black, '_white', '_black_fr', ..."""
    return "" if t == "black" else "_" + t


def gamecode(t):
    return TARGETS[t][2]


def sha1(t):
    return TARGETS[t][4]


def by_gamecode(code):
    if isinstance(code, bytes):
        code = code.decode("ascii", "replace")
    for name, v in TARGETS.items():
        if v[2] == code:
            return name
    return None
