/*
 * Copyright (c) 1991, 1992 Antonio Costa, INESC-Norte.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by Antonio Costa, at INESC-Norte. The name of the author and
 * INESC-Norte may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
#include "extern.h"

/**********************************************************************
 *    SCENE - Colors - Version 1.3.2                                  *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, August 1992            *
 **********************************************************************/

#define COLORS (sizeof(colors) / sizeof(color_struct))

typedef struct
{
  char           *name;
  rgb_struct      color;
} color_struct;

/*
 * These colors must be in sorted order.
 */

static
color_struct    colors[] = {
#ifndef SMALL_COLORS
  "AliceBlue", {0.941176, 0.972549, 1},
  "AntiqueWhite", {0.980392, 0.921569, 0.843137},
  "AntiqueWhite1", {1, 0.937255, 0.858824},
  "AntiqueWhite2", {0.933333, 0.87451, 0.8},
  "AntiqueWhite3", {0.803922, 0.752941, 0.690196},
  "AntiqueWhite4", {0.545098, 0.513725, 0.470588},
  "Aquamarine", {0.439216, 0.858824, 0.576471},
  "Black", {0, 0, 0},
  "BlanchedAlmond", {1, 0.921569, 0.803922},
  "Blue", {0, 0, 1},
  "BlueViolet", {0.541176, 0.168627, 0.886275},
  "Brown", {0.647059, 0.164706, 0.164706},
  "CadetBlue", {0.372549, 0.623529, 0.623529},
  "CadetBlue1", {0.596078, 0.960784, 1},
  "CadetBlue2", {0.556863, 0.898039, 0.933333},
  "CadetBlue3", {0.478431, 0.772549, 0.803922},
  "Coral", {1, 0.498039, 0},
  "CornflowerBlue", {0.392157, 0.584314, 0.929412},
  "Cyan", {0, 1, 1},
  "DarkGoldenrod", {0.721569, 0.52549, 0.0431373},
  "DarkGreen", {0.184314, 0.309804, 0.184314},
  "DarkKhaki", {0.741176, 0.717647, 0.419608},
  "DarkOliveGreen", {0.309804, 0.309804, 0.184314},
  "DarkOliveGreen1", {0.792157, 1, 0.439216},
  "DarkOliveGreen2", {0.737255, 0.933333, 0.407843},
  "DarkOrange", {1, 0.54902, 0},
  "DarkOrchid", {0.6, 0.196078, 0.8},
  "DarkOrchid1", {0.74902, 0.243137, 1},
  "DarkOrchid2", {0.698039, 0.227451, 0.933333},
  "DarkOrchid3", {0.603922, 0.196078, 0.803922},
  "DarkOrchid4", {0.407843, 0.133333, 0.545098},
  "DarkSalmon", {0.913725, 0.588235, 0.478431},
  "DarkSeaGreen", {0.560784, 0.737255, 0.560784},
  "DarkSeaGreen1", {0.756863, 1, 0.756863},
  "DarkSeaGreen2", {0.705882, 0.933333, 0.705882},
  "DarkSeaGreen3", {0.607843, 0.803922, 0.607843},
  "DarkSeaGreen4", {0.411765, 0.545098, 0.411765},
  "DarkSlateBlue", {0.419608, 0.137255, 0.556863},
  "DarkSlateGray", {0.184314, 0.309804, 0.309804},
  "DarkSlateGray1", {0.592157, 1, 1},
  "DarkSlateGray2", {0.552941, 0.933333, 0.933333},
  "DarkSlateGray3", {0.47451, 0.803922, 0.803922},
  "DarkSlateGrey", {0.184314, 0.309804, 0.309804},
  "DarkTurquoise", {0.439216, 0.576471, 0.858824},
  "DarkViolet", {0.580392, 0, 0.827451},
  "DeepPink", {1, 0.0784314, 0.576471},
  "DeepPink1", {1, 0.0784314, 0.576471},
  "DeepPink2", {0.933333, 0.0705882, 0.537255},
  "DeepPink3", {0.803922, 0.0627451, 0.462745},
  "DimGray", {0.411765, 0.411765, 0.411765},
  "DimGrey", {0.411765, 0.411765, 0.411765},
  "Firebrick", {0.556863, 0.137255, 0.137255},
  "FloralWhite", {1, 0.980392, 0.941176},
  "ForestGreen", {0.137255, 0.556863, 0.137255},
  "GhostWhite", {0.972549, 0.972549, 1},
  "Gold", {0.8, 0.498039, 0.196078},
  "Goldenrod", {0.858824, 0.858824, 0.439216},
  "Gray", {0.752941, 0.752941, 0.752941},
  "Green", {0, 1, 0},
  "GreenYellow", {0.678431, 1, 0.184314},
  "Grey", {0.752941, 0.752941, 0.752941},
  "HotPink", {1, 0.411765, 0.705882},
  "HotPink1", {1, 0.431373, 0.705882},
  "HotPink2", {0.933333, 0.415686, 0.654902},
  "HotPink3", {0.803922, 0.376471, 0.564706},
  "HotPink4", {0.545098, 0.227451, 0.384314},
  "IndianRed", {0.803922, 0.360784, 0.360784},
  "IndianRed1", {1, 0.415686, 0.415686},
  "Khaki", {0.623529, 0.623529, 0.372549},
  "LavenderBlush", {1, 0.941176, 0.960784},
  "LavenderBlush1", {1, 0.941176, 0.960784},
  "LavenderBlush2", {0.933333, 0.878431, 0.898039},
  "LavenderBlush3", {0.803922, 0.756863, 0.772549},
  "LavenderBlush4", {0.545098, 0.513725, 0.52549},
  "LawnGreen", {0.486275, 0.988235, 0},
  "LemonChiffon", {1, 0.980392, 0.803922},
  "LemonChiffon1", {1, 0.980392, 0.803922},
  "LemonChiffon2", {0.933333, 0.913725, 0.74902},
  "LemonChiffon3", {0.803922, 0.788235, 0.647059},
  "LemonChiffon4", {0.545098, 0.537255, 0.439216},
  "LightBlue", {0.678431, 0.847059, 0.901961},
  "LightBlue1", {0.74902, 0.937255, 1},
  "LightBlue2", {0.698039, 0.87451, 0.933333},
  "LightBlue3", {0.603922, 0.752941, 0.803922},
  "LightBlue4", {0.407843, 0.513725, 0.545098},
  "LightCoral", {0.941176, 0.501961, 0.501961},
  "LightCyan", {0.878431, 1, 1},
  "LightCyan1", {0.878431, 1, 1},
  "LightCyan2", {0.819608, 0.933333, 0.933333},
  "LightCyan3", {0.705882, 0.803922, 0.803922},
  "LightCyan4", {0.478431, 0.545098, 0.545098},
  "LightGoldenrod", {0.933333, 0.866667, 0.509804},
  "LightGoldenrod1", {1, 0.92549, 0.545098},
  "LightGoldenrod2", {0.933333, 0.862745, 0.509804},
  "LightGoldenrod3", {0.803922, 0.745098, 0.439216},
  "LightGoldenrodYellow", {0.980392, 0.980392, 0.823529},
  "LightGray", {0.827451, 0.827451, 0.827451},
  "LightGrey", {0.827451, 0.827451, 0.827451},
  "LightPink", {1, 0.713725, 0.756863},
  "LightPink1", {1, 0.682353, 0.72549},
  "LightPink2", {0.933333, 0.635294, 0.678431},
  "LightPink3", {0.803922, 0.54902, 0.584314},
  "LightPink4", {0.545098, 0.372549, 0.396078},
  "LightSalmon", {1, 0.627451, 0.478431},
  "LightSalmon1", {1, 0.627451, 0.478431},
  "LightSalmon2", {0.933333, 0.584314, 0.447059},
  "LightSkyBlue", {0.529412, 0.807843, 0.980392},
  "LightSkyBlue1", {0.690196, 0.886275, 1},
  "LightSkyBlue2", {0.643137, 0.827451, 0.933333},
  "LightSkyBlue3", {0.552941, 0.713725, 0.803922},
  "LightSlateBlue", {0.517647, 0.439216, 1},
  "LightSlateGray", {0.466667, 0.533333, 0.6},
  "LightSlateGrey", {0.466667, 0.533333, 0.6},
  "LightSteelBlue", {0.690196, 0.768627, 0.870588},
  "LightSteelBlue1", {0.792157, 0.882353, 1},
  "LightSteelBlue2", {0.737255, 0.823529, 0.933333},
  "LightSteelBlue3", {0.635294, 0.709804, 0.803922},
  "LightSteelBlue4", {0.431373, 0.482353, 0.545098},
  "LightYellow", {1, 1, 0.878431},
  "LightYellow1", {1, 1, 0.878431},
  "LightYellow2", {0.933333, 0.933333, 0.819608},
  "LightYellow3", {0.803922, 0.803922, 0.705882},
  "LightYellow4", {0.545098, 0.545098, 0.478431},
  "LimeGreen", {0.196078, 0.8, 0.196078},
  "Magenta", {1, 0, 1},
  "Maroon", {0.556863, 0.137255, 0.419608},
  "MediumAquamarine", {0.4, 0.803922, 0.666667},
  "MediumBlue", {0.196078, 0.196078, 0.8},
  "MediumForestGreen", {0.419608, 0.556863, 0.137255},
  "MediumGoldenrod", {0.917647, 0.917647, 0.678431},
  "MediumOrchid", {0.729412, 0.333333, 0.827451},
  "MediumOrchid1", {0.878431, 0.4, 1},
  "MediumOrchid2", {0.819608, 0.372549, 0.933333},
  "MediumOrchid3", {0.705882, 0.321569, 0.803922},
  "MediumOrchid4", {0.478431, 0.215686, 0.545098},
  "MediumPurple", {0.576471, 0.439216, 0.858824},
  "MediumPurple1", {0.670588, 0.509804, 1},
  "MediumPurple2", {0.623529, 0.47451, 0.933333},
  "MediumPurple3", {0.537255, 0.407843, 0.803922},
  "MediumSeaGreen", {0.258824, 0.435294, 0.258824},
  "MediumSlateBlue", {0.482353, 0.407843, 0.933333},
  "MediumSpringGreen", {0.498039, 1, 0},
  "MediumTurquoise", {0.439216, 0.858824, 0.858824},
  "MediumVioletRed", {0.780392, 0.0823529, 0.521569},
  "MidnightBlue", {0.184314, 0.184314, 0.309804},
  "MintCream", {0.960784, 1, 0.980392},
  "MistyRose", {1, 0.894118, 0.882353},
  "MistyRose1", {1, 0.894118, 0.882353},
  "MistyRose2", {0.933333, 0.835294, 0.823529},
  "MistyRose3", {0.803922, 0.717647, 0.709804},
  "MistyRose4", {0.545098, 0.490196, 0.482353},
  "NavajoWhite", {1, 0.870588, 0.678431},
  "NavajoWhite1", {1, 0.870588, 0.678431},
  "NavajoWhite2", {0.933333, 0.811765, 0.631373},
  "NavajoWhite3", {0.803922, 0.701961, 0.545098},
  "Navy", {0.137255, 0.137255, 0.556863},
  "NavyBlue", {0.137255, 0.137255, 0.556863},
  "OldLace", {0.992157, 0.960784, 0.901961},
  "OliveDrab", {0.419608, 0.556863, 0.137255},
  "Orange", {0.8, 0.196078, 0.196078},
  "OrangeRed", {1, 0.270588, 0},
  "Orchid", {0.858824, 0.439216, 0.858824},
  "PaleGoldenrod", {0.933333, 0.909804, 0.666667},
  "PaleGreen", {0.596078, 0.984314, 0.596078},
  "PaleGreen1", {0.603922, 1, 0.603922},
  "PaleGreen2", {0.564706, 0.933333, 0.564706},
  "PaleGreen3", {0.486275, 0.803922, 0.486275},
  "PaleTurquoise", {0.686275, 0.933333, 0.933333},
  "PaleTurquoise1", {0.733333, 1, 1},
  "PaleTurquoise2", {0.682353, 0.933333, 0.933333},
  "PaleTurquoise3", {0.588235, 0.803922, 0.803922},
  "PaleTurquoise4", {0.4, 0.545098, 0.545098},
  "PaleVioletRed", {0.858824, 0.439216, 0.576471},
  "PaleVioletRed1", {1, 0.509804, 0.670588},
  "PaleVioletRed2", {0.933333, 0.47451, 0.623529},
  "PaleVioletRed3", {0.803922, 0.407843, 0.537255},
  "PapayaWhip", {1, 0.937255, 0.835294},
  "PeachPuff", {1, 0.854902, 0.72549},
  "PeachPuff1", {1, 0.854902, 0.72549},
  "PeachPuff2", {0.933333, 0.796078, 0.678431},
  "PeachPuff3", {0.803922, 0.686275, 0.584314},
  "PeachPuff4", {0.545098, 0.466667, 0.396078},
  "Pink", {0.737255, 0.560784, 0.560784},
  "Plum", {0.917647, 0.678431, 0.917647},
  "PowderBlue", {0.690196, 0.878431, 0.901961},
  "Red", {1, 0, 0},
  "RosyBrown", {0.737255, 0.560784, 0.560784},
  "RosyBrown1", {1, 0.756863, 0.756863},
  "RosyBrown2", {0.933333, 0.705882, 0.705882},
  "RosyBrown3", {0.803922, 0.607843, 0.607843},
  "RosyBrown4", {0.545098, 0.411765, 0.411765},
  "SaddleBrown", {0.545098, 0.270588, 0.0745098},
  "Salmon", {0.435294, 0.258824, 0.258824},
  "SandyBrown", {0.956863, 0.643137, 0.376471},
  "SeaGreen", {0.137255, 0.556863, 0.419608},
  "Sienna", {0.556863, 0.419608, 0.137255},
  "SkyBlue", {0.529412, 0.807843, 0.921569},
  "SkyBlue1", {0.529412, 0.807843, 1},
  "SkyBlue2", {0.494118, 0.752941, 0.933333},
  "SkyBlue3", {0.423529, 0.65098, 0.803922},
  "SlateBlue", {0.415686, 0.352941, 0.803922},
  "SlateBlue1", {0.513725, 0.435294, 1},
  "SlateBlue2", {0.478431, 0.403922, 0.933333},
  "SlateBlue3", {0.411765, 0.34902, 0.803922},
  "SlateGray", {0.439216, 0.501961, 0.564706},
  "SlateGray1", {0.776471, 0.886275, 1},
  "SlateGray2", {0.72549, 0.827451, 0.933333},
  "SlateGray3", {0.623529, 0.713725, 0.803922},
  "SlateGray4", {0.423529, 0.482353, 0.545098},
  "SlateGrey", {0.439216, 0.501961, 0.564706},
  "SpringGreen", {0, 1, 0.498039},
  "SteelBlue", {0.137255, 0.419608, 0.556863},
  "Tan", {0.858824, 0.576471, 0.439216},
  "Thistle", {0.847059, 0.74902, 0.847059},
  "Turquoise", {0.678431, 0.917647, 0.917647},
  "Violet", {0.309804, 0.184314, 0.309804},
  "VioletRed", {0.815686, 0.12549, 0.564706},
  "VioletRed1", {1, 0.243137, 0.588235},
  "VioletRed2", {0.933333, 0.227451, 0.54902},
  "VioletRed3", {0.803922, 0.196078, 0.470588},
  "Wheat", {0.847059, 0.847059, 0.74902},
  "White", {0.988235, 0.988235, 0.988235},
  "WhiteSmoke", {0.960784, 0.960784, 0.960784},
  "Yellow", {1, 1, 0},
  "YellowGreen", {0.603922, 0.803922, 0.196078},
#endif
  "alice_blue", {0.941176, 0.972549, 1},
  "antique_white", {0.980392, 0.921569, 0.843137},
  "antique_white1", {1, 0.937255, 0.858824},
  "antique_white2", {0.933333, 0.87451, 0.8},
  "antique_white3", {0.803922, 0.752941, 0.690196},
  "antique_white4", {0.545098, 0.513725, 0.470588},
  "aquamarine", {0.439216, 0.858824, 0.576471},
  "aquamarine0", {0.498039, 1, 0.831373},
  "aquamarine1", {0.498039, 1, 0.831373},
  "aquamarine2", {0.462745, 0.933333, 0.776471},
  "aquamarine3", {0.4, 0.803922, 0.666667},
  "azure", {0.941176, 1, 1},
  "azure1", {0.941176, 1, 1},
  "azure2", {0.878431, 0.933333, 0.933333},
  "azure3", {0.756863, 0.803922, 0.803922},
  "azure4", {0.513725, 0.545098, 0.545098},
  "beige", {0.960784, 0.960784, 0.862745},
  "bisque", {1, 0.894118, 0.768627},
  "bisque1", {1, 0.894118, 0.768627},
  "bisque2", {0.933333, 0.835294, 0.717647},
  "bisque3", {0.803922, 0.717647, 0.619608},
  "bisque4", {0.545098, 0.490196, 0.419608},
  "black", {0, 0, 0},
  "blanched_almond", {1, 0.921569, 0.803922},
  "blue", {0, 0, 1},
  "blue_violet", {0.541176, 0.168627, 0.886275},
  "brown", {0.647059, 0.164706, 0.164706},
  "burlywood", {0.870588, 0.721569, 0.529412},
  "burlywood1", {1, 0.827451, 0.607843},
  "burlywood2", {0.933333, 0.772549, 0.568627},
  "burlywood3", {0.803922, 0.666667, 0.490196},
  "cadet_blue", {0.372549, 0.623529, 0.623529},
  "cadet_blue1", {0.596078, 0.960784, 1},
  "cadet_blue2", {0.556863, 0.898039, 0.933333},
  "cadet_blue3", {0.478431, 0.772549, 0.803922},
  "chartreuse", {0.498039, 1, 0},
  "chocolate", {0.823529, 0.411765, 0.117647},
  "coral", {1, 0.498039, 0.313725},
  "coral0", {1, 0.498039, 0},
  "cornflower_blue", {0.392157, 0.584314, 0.929412},
  "cornsilk", {1, 0.972549, 0.862745},
  "cornsilk1", {1, 0.972549, 0.862745},
  "cornsilk2", {0.933333, 0.909804, 0.803922},
  "cornsilk3", {0.803922, 0.784314, 0.694118},
  "cornsilk4", {0.545098, 0.533333, 0.470588},
  "cyan", {0, 1, 1},
  "dark_goldenrod", {0.721569, 0.52549, 0.0431373},
  "dark_green", {0.184314, 0.309804, 0.184314},
  "dark_khaki", {0.741176, 0.717647, 0.419608},
  "dark_olive_green", {0.309804, 0.309804, 0.184314},
  "dark_olive_green1", {0.792157, 1, 0.439216},
  "dark_olive_green2", {0.737255, 0.933333, 0.407843},
  "dark_orange", {1, 0.54902, 0},
  "dark_orchid", {0.6, 0.196078, 0.8},
  "dark_orchid1", {0.74902, 0.243137, 1},
  "dark_orchid2", {0.698039, 0.227451, 0.933333},
  "dark_orchid3", {0.603922, 0.196078, 0.803922},
  "dark_orchid4", {0.407843, 0.133333, 0.545098},
  "dark_salmon", {0.913725, 0.588235, 0.478431},
  "dark_sea_green", {0.560784, 0.737255, 0.560784},
  "dark_sea_green1", {0.756863, 1, 0.756863},
  "dark_sea_green2", {0.705882, 0.933333, 0.705882},
  "dark_sea_green3", {0.607843, 0.803922, 0.607843},
  "dark_sea_green4", {0.411765, 0.545098, 0.411765},
  "dark_slate_blue", {0.419608, 0.137255, 0.556863},
  "dark_slate_gray", {0.184314, 0.309804, 0.309804},
  "dark_slate_gray1", {0.592157, 1, 1},
  "dark_slate_gray2", {0.552941, 0.933333, 0.933333},
  "dark_slate_gray3", {0.47451, 0.803922, 0.803922},
  "dark_slate_grey", {0.184314, 0.309804, 0.309804},
  "dark_turquoise", {0.439216, 0.576471, 0.858824},
  "dark_violet", {0.580392, 0, 0.827451},
  "deep_pink", {1, 0.0784314, 0.576471},
  "deep_pink1", {1, 0.0784314, 0.576471},
  "deep_pink2", {0.933333, 0.0705882, 0.537255},
  "deep_pink3", {0.803922, 0.0627451, 0.462745},
  "dim_gray", {0.411765, 0.411765, 0.411765},
  "dim_grey", {0.411765, 0.411765, 0.411765},
  "firebrick", {0.556863, 0.137255, 0.137255},
  "firebrick0", {0.698039, 0.133333, 0.133333},
  "floral_white", {1, 0.980392, 0.941176},
  "forest_green", {0.137255, 0.556863, 0.137255},
  "gainsboro", {0.862745, 0.862745, 0.862745},
  "ghost_white", {0.972549, 0.972549, 1},
  "gold", {0.8, 0.498039, 0.196078},
  "gold0", {1, 0.843137, 0},
  "goldenrod", {0.854902, 0.647059, 0.12549},
  "goldenrod0", {0.858824, 0.858824, 0.439216},
  "gray", {0.752941, 0.752941, 0.752941},
  "gray100", {1, 1, 1},
  "gray40", {0.4, 0.4, 0.4},
  "gray41", {0.411765, 0.411765, 0.411765},
  "gray42", {0.419608, 0.419608, 0.419608},
  "gray43", {0.431373, 0.431373, 0.431373},
  "gray44", {0.439216, 0.439216, 0.439216},
  "gray45", {0.45098, 0.45098, 0.45098},
  "gray46", {0.458824, 0.458824, 0.458824},
  "gray47", {0.470588, 0.470588, 0.470588},
  "gray48", {0.478431, 0.478431, 0.478431},
  "gray49", {0.490196, 0.490196, 0.490196},
  "gray50", {0.498039, 0.498039, 0.498039},
  "gray51", {0.509804, 0.509804, 0.509804},
  "gray52", {0.521569, 0.521569, 0.521569},
  "gray53", {0.529412, 0.529412, 0.529412},
  "gray54", {0.541176, 0.541176, 0.541176},
  "gray55", {0.54902, 0.54902, 0.54902},
  "gray56", {0.560784, 0.560784, 0.560784},
  "gray57", {0.568627, 0.568627, 0.568627},
  "gray58", {0.580392, 0.580392, 0.580392},
  "gray59", {0.588235, 0.588235, 0.588235},
  "gray60", {0.6, 0.6, 0.6},
  "gray61", {0.611765, 0.611765, 0.611765},
  "gray62", {0.619608, 0.619608, 0.619608},
  "gray63", {0.631373, 0.631373, 0.631373},
  "gray64", {0.639216, 0.639216, 0.639216},
  "gray65", {0.65098, 0.65098, 0.65098},
  "gray66", {0.658824, 0.658824, 0.658824},
  "gray67", {0.670588, 0.670588, 0.670588},
  "gray68", {0.678431, 0.678431, 0.678431},
  "gray69", {0.690196, 0.690196, 0.690196},
  "gray70", {0.701961, 0.701961, 0.701961},
  "gray71", {0.709804, 0.709804, 0.709804},
  "gray72", {0.721569, 0.721569, 0.721569},
  "gray73", {0.729412, 0.729412, 0.729412},
  "gray74", {0.741176, 0.741176, 0.741176},
  "gray75", {0.74902, 0.74902, 0.74902},
  "gray76", {0.760784, 0.760784, 0.760784},
  "gray77", {0.768627, 0.768627, 0.768627},
  "gray78", {0.780392, 0.780392, 0.780392},
  "gray79", {0.788235, 0.788235, 0.788235},
  "gray80", {0.8, 0.8, 0.8},
  "gray81", {0.811765, 0.811765, 0.811765},
  "gray82", {0.819608, 0.819608, 0.819608},
  "gray83", {0.831373, 0.831373, 0.831373},
  "gray84", {0.839216, 0.839216, 0.839216},
  "gray85", {0.85098, 0.85098, 0.85098},
  "gray86", {0.858824, 0.858824, 0.858824},
  "gray87", {0.870588, 0.870588, 0.870588},
  "gray88", {0.878431, 0.878431, 0.878431},
  "gray89", {0.890196, 0.890196, 0.890196},
  "gray90", {0.898039, 0.898039, 0.898039},
  "gray91", {0.909804, 0.909804, 0.909804},
  "gray92", {0.921569, 0.921569, 0.921569},
  "gray93", {0.929412, 0.929412, 0.929412},
  "gray94", {0.941176, 0.941176, 0.941176},
  "gray95", {0.94902, 0.94902, 0.94902},
  "gray96", {0.960784, 0.960784, 0.960784},
  "gray97", {0.968627, 0.968627, 0.968627},
  "gray98", {0.980392, 0.980392, 0.980392},
  "gray99", {0.988235, 0.988235, 0.988235},
  "green", {0, 1, 0},
  "green_yellow", {0.678431, 1, 0.184314},
  "grey", {0.752941, 0.752941, 0.752941},
  "grey100", {1, 1, 1},
  "grey40", {0.4, 0.4, 0.4},
  "grey41", {0.411765, 0.411765, 0.411765},
  "grey42", {0.419608, 0.419608, 0.419608},
  "grey43", {0.431373, 0.431373, 0.431373},
  "grey44", {0.439216, 0.439216, 0.439216},
  "grey45", {0.45098, 0.45098, 0.45098},
  "grey46", {0.458824, 0.458824, 0.458824},
  "grey47", {0.470588, 0.470588, 0.470588},
  "grey48", {0.478431, 0.478431, 0.478431},
  "grey49", {0.490196, 0.490196, 0.490196},
  "grey50", {0.498039, 0.498039, 0.498039},
  "grey51", {0.509804, 0.509804, 0.509804},
  "grey52", {0.521569, 0.521569, 0.521569},
  "grey53", {0.529412, 0.529412, 0.529412},
  "grey54", {0.541176, 0.541176, 0.541176},
  "grey55", {0.54902, 0.54902, 0.54902},
  "grey56", {0.560784, 0.560784, 0.560784},
  "grey57", {0.568627, 0.568627, 0.568627},
  "grey58", {0.580392, 0.580392, 0.580392},
  "grey59", {0.588235, 0.588235, 0.588235},
  "grey60", {0.6, 0.6, 0.6},
  "grey61", {0.611765, 0.611765, 0.611765},
  "grey62", {0.619608, 0.619608, 0.619608},
  "grey63", {0.631373, 0.631373, 0.631373},
  "grey64", {0.639216, 0.639216, 0.639216},
  "grey65", {0.65098, 0.65098, 0.65098},
  "grey66", {0.658824, 0.658824, 0.658824},
  "grey67", {0.670588, 0.670588, 0.670588},
  "grey68", {0.678431, 0.678431, 0.678431},
  "grey69", {0.690196, 0.690196, 0.690196},
  "grey70", {0.701961, 0.701961, 0.701961},
  "grey71", {0.709804, 0.709804, 0.709804},
  "grey72", {0.721569, 0.721569, 0.721569},
  "grey73", {0.729412, 0.729412, 0.729412},
  "grey74", {0.741176, 0.741176, 0.741176},
  "grey75", {0.74902, 0.74902, 0.74902},
  "grey76", {0.760784, 0.760784, 0.760784},
  "grey77", {0.768627, 0.768627, 0.768627},
  "grey78", {0.780392, 0.780392, 0.780392},
  "grey79", {0.788235, 0.788235, 0.788235},
  "grey80", {0.8, 0.8, 0.8},
  "grey81", {0.811765, 0.811765, 0.811765},
  "grey82", {0.819608, 0.819608, 0.819608},
  "grey83", {0.831373, 0.831373, 0.831373},
  "grey84", {0.839216, 0.839216, 0.839216},
  "grey85", {0.85098, 0.85098, 0.85098},
  "grey86", {0.858824, 0.858824, 0.858824},
  "grey87", {0.870588, 0.870588, 0.870588},
  "grey88", {0.878431, 0.878431, 0.878431},
  "grey89", {0.890196, 0.890196, 0.890196},
  "grey90", {0.898039, 0.898039, 0.898039},
  "grey91", {0.909804, 0.909804, 0.909804},
  "grey92", {0.921569, 0.921569, 0.921569},
  "grey93", {0.929412, 0.929412, 0.929412},
  "grey94", {0.941176, 0.941176, 0.941176},
  "grey95", {0.94902, 0.94902, 0.94902},
  "grey96", {0.960784, 0.960784, 0.960784},
  "grey97", {0.968627, 0.968627, 0.968627},
  "grey98", {0.980392, 0.980392, 0.980392},
  "grey99", {0.988235, 0.988235, 0.988235},
  "honeydew", {0.941176, 1, 0.941176},
  "honeydew1", {0.941176, 1, 0.941176},
  "honeydew2", {0.878431, 0.933333, 0.878431},
  "honeydew3", {0.756863, 0.803922, 0.756863},
  "honeydew4", {0.513725, 0.545098, 0.513725},
  "hot_pink", {1, 0.411765, 0.705882},
  "hot_pink1", {1, 0.431373, 0.705882},
  "hot_pink2", {0.933333, 0.415686, 0.654902},
  "hot_pink3", {0.803922, 0.376471, 0.564706},
  "hot_pink4", {0.545098, 0.227451, 0.384314},
  "indian_red", {0.803922, 0.360784, 0.360784},
  "indian_red0", {1, 0.415686, 0.415686},
  "ivory", {1, 1, 0.941176},
  "ivory1", {1, 1, 0.941176},
  "ivory2", {0.933333, 0.933333, 0.878431},
  "ivory3", {0.803922, 0.803922, 0.756863},
  "ivory4", {0.545098, 0.545098, 0.513725},
  "khaki", {0.623529, 0.623529, 0.372549},
  "khaki0", {0.941176, 0.901961, 0.54902},
  "khaki1", {1, 0.964706, 0.560784},
  "khaki2", {0.933333, 0.901961, 0.521569},
  "khaki3", {0.803922, 0.776471, 0.45098},
  "lavender", {0.901961, 0.901961, 0.980392},
  "lavender_blush", {1, 0.941176, 0.960784},
  "lavender_blush1", {1, 0.941176, 0.960784},
  "lavender_blush2", {0.933333, 0.878431, 0.898039},
  "lavender_blush3", {0.803922, 0.756863, 0.772549},
  "lavender_blush4", {0.545098, 0.513725, 0.52549},
  "lawn_green", {0.486275, 0.988235, 0},
  "lemon_chiffon", {1, 0.980392, 0.803922},
  "lemon_chiffon1", {1, 0.980392, 0.803922},
  "lemon_chiffon2", {0.933333, 0.913725, 0.74902},
  "lemon_chiffon3", {0.803922, 0.788235, 0.647059},
  "lemon_chiffon4", {0.545098, 0.537255, 0.439216},
  "light_blue", {0.678431, 0.847059, 0.901961},
  "light_blue1", {0.74902, 0.937255, 1},
  "light_blue2", {0.698039, 0.87451, 0.933333},
  "light_blue3", {0.603922, 0.752941, 0.803922},
  "light_blue4", {0.407843, 0.513725, 0.545098},
  "light_coral", {0.941176, 0.501961, 0.501961},
  "light_cyan", {0.878431, 1, 1},
  "light_cyan1", {0.878431, 1, 1},
  "light_cyan2", {0.819608, 0.933333, 0.933333},
  "light_cyan3", {0.705882, 0.803922, 0.803922},
  "light_cyan4", {0.478431, 0.545098, 0.545098},
  "light_goldenrod", {0.933333, 0.866667, 0.509804},
  "light_goldenrod1", {1, 0.92549, 0.545098},
  "light_goldenrod2", {0.933333, 0.862745, 0.509804},
  "light_goldenrod3", {0.803922, 0.745098, 0.439216},
  "light_goldenrod_yellow", {0.980392, 0.980392, 0.823529},
  "light_gray", {0.827451, 0.827451, 0.827451},
  "light_grey", {0.827451, 0.827451, 0.827451},
  "light_pink", {1, 0.713725, 0.756863},
  "light_pink1", {1, 0.682353, 0.72549},
  "light_pink2", {0.933333, 0.635294, 0.678431},
  "light_pink3", {0.803922, 0.54902, 0.584314},
  "light_pink4", {0.545098, 0.372549, 0.396078},
  "light_salmon", {1, 0.627451, 0.478431},
  "light_salmon1", {1, 0.627451, 0.478431},
  "light_salmon2", {0.933333, 0.584314, 0.447059},
  "light_sky_blue", {0.529412, 0.807843, 0.980392},
  "light_sky_blue1", {0.690196, 0.886275, 1},
  "light_sky_blue2", {0.643137, 0.827451, 0.933333},
  "light_sky_blue3", {0.552941, 0.713725, 0.803922},
  "light_slate_blue", {0.517647, 0.439216, 1},
  "light_slate_gray", {0.466667, 0.533333, 0.6},
  "light_slate_grey", {0.466667, 0.533333, 0.6},
  "light_steel_blue", {0.690196, 0.768627, 0.870588},
  "light_steel_blue1", {0.792157, 0.882353, 1},
  "light_steel_blue2", {0.737255, 0.823529, 0.933333},
  "light_steel_blue3", {0.635294, 0.709804, 0.803922},
  "light_steel_blue4", {0.431373, 0.482353, 0.545098},
  "light_yellow", {1, 1, 0.878431},
  "light_yellow1", {1, 1, 0.878431},
  "light_yellow2", {0.933333, 0.933333, 0.819608},
  "light_yellow3", {0.803922, 0.803922, 0.705882},
  "light_yellow4", {0.545098, 0.545098, 0.478431},
  "lime_green", {0.196078, 0.8, 0.196078},
  "linen", {0.980392, 0.941176, 0.901961},
  "magenta", {1, 0, 1},
  "magenta2", {0.933333, 0, 0.933333},
  "magenta3", {0.803922, 0, 0.803922},
  "magenta4", {0.545098, 0, 0.545098},
  "maroon", {0.556863, 0.137255, 0.419608},
  "maroon0", {0.690196, 0.188235, 0.376471},
  "maroon1", {1, 0.203922, 0.701961},
  "maroon2", {0.933333, 0.188235, 0.654902},
  "maroon3", {0.803922, 0.160784, 0.564706},
  "medium_aquamarine", {0.4, 0.803922, 0.666667},
  "medium_blue", {0.196078, 0.196078, 0.8},
  "medium_forest_green", {0.419608, 0.556863, 0.137255},
  "medium_goldenrod", {0.917647, 0.917647, 0.678431},
  "medium_orchid", {0.729412, 0.333333, 0.827451},
  "medium_orchid1", {0.878431, 0.4, 1},
  "medium_orchid2", {0.819608, 0.372549, 0.933333},
  "medium_orchid3", {0.705882, 0.321569, 0.803922},
  "medium_orchid4", {0.478431, 0.215686, 0.545098},
  "medium_purple", {0.576471, 0.439216, 0.858824},
  "medium_purple1", {0.670588, 0.509804, 1},
  "medium_purple2", {0.623529, 0.47451, 0.933333},
  "medium_purple3", {0.537255, 0.407843, 0.803922},
  "medium_sea_green", {0.258824, 0.435294, 0.258824},
  "medium_slate_blue", {0.482353, 0.407843, 0.933333},
  "medium_spring_green", {0.498039, 1, 0},
  "medium_turquoise", {0.439216, 0.858824, 0.858824},
  "medium_violet_red", {0.780392, 0.0823529, 0.521569},
  "midnight_blue", {0.184314, 0.184314, 0.309804},
  "mint_cream", {0.960784, 1, 0.980392},
  "misty_rose", {1, 0.894118, 0.882353},
  "misty_rose1", {1, 0.894118, 0.882353},
  "misty_rose2", {0.933333, 0.835294, 0.823529},
  "misty_rose3", {0.803922, 0.717647, 0.709804},
  "misty_rose4", {0.545098, 0.490196, 0.482353},
  "moccasin", {1, 0.894118, 0.709804},
  "navajo_white", {1, 0.870588, 0.678431},
  "navajo_white1", {1, 0.870588, 0.678431},
  "navajo_white2", {0.933333, 0.811765, 0.631373},
  "navajo_white3", {0.803922, 0.701961, 0.545098},
  "navy", {0.137255, 0.137255, 0.556863},
  "navy_blue", {0.137255, 0.137255, 0.556863},
  "old_lace", {0.992157, 0.960784, 0.901961},
  "olive_drab", {0.419608, 0.556863, 0.137255},
  "orange", {0.8, 0.196078, 0.196078},
  "orange0", {1, 0.647059, 0},
  "orange_red", {1, 0.270588, 0},
  "orchid", {0.854902, 0.439216, 0.839216},
  "orchid0", {0.858824, 0.439216, 0.858824},
  "orchid1", {1, 0.513725, 0.980392},
  "orchid2", {0.933333, 0.478431, 0.913725},
  "orchid3", {0.803922, 0.411765, 0.788235},
  "orchid4", {0.545098, 0.278431, 0.537255},
  "pale_goldenrod", {0.933333, 0.909804, 0.666667},
  "pale_green", {0.596078, 0.984314, 0.596078},
  "pale_green1", {0.603922, 1, 0.603922},
  "pale_green2", {0.564706, 0.933333, 0.564706},
  "pale_green3", {0.486275, 0.803922, 0.486275},
  "pale_turquoise", {0.686275, 0.933333, 0.933333},
  "pale_turquoise1", {0.733333, 1, 1},
  "pale_turquoise2", {0.682353, 0.933333, 0.933333},
  "pale_turquoise3", {0.588235, 0.803922, 0.803922},
  "pale_turquoise4", {0.4, 0.545098, 0.545098},
  "pale_violet_red", {0.858824, 0.439216, 0.576471},
  "pale_violet_red1", {1, 0.509804, 0.670588},
  "pale_violet_red2", {0.933333, 0.47451, 0.623529},
  "pale_violet_red3", {0.803922, 0.407843, 0.537255},
  "papaya_whip", {1, 0.937255, 0.835294},
  "peach_puff", {1, 0.854902, 0.72549},
  "peach_puff1", {1, 0.854902, 0.72549},
  "peach_puff2", {0.933333, 0.796078, 0.678431},
  "peach_puff3", {0.803922, 0.686275, 0.584314},
  "peach_puff4", {0.545098, 0.466667, 0.396078},
  "peru", {0.803922, 0.521569, 0.247059},
  "pink", {0.737255, 0.560784, 0.560784},
  "pink0", {1, 0.752941, 0.796078},
  "pink1", {1, 0.709804, 0.772549},
  "pink2", {0.933333, 0.662745, 0.721569},
  "pink3", {0.803922, 0.568627, 0.619608},
  "pink4", {0.545098, 0.388235, 0.423529},
  "plum", {0.866667, 0.627451, 0.866667},
  "plum0", {0.917647, 0.678431, 0.917647},
  "plum1", {1, 0.733333, 1},
  "plum2", {0.933333, 0.682353, 0.933333},
  "plum3", {0.803922, 0.588235, 0.803922},
  "plum4", {0.545098, 0.4, 0.545098},
  "powder_blue", {0.690196, 0.878431, 0.901961},
  "purple", {0.627451, 0.12549, 0.941176},
  "purple1", {0.607843, 0.188235, 1},
  "purple2", {0.568627, 0.172549, 0.933333},
  "purple3", {0.490196, 0.14902, 0.803922},
  "red", {1, 0, 0},
  "rosy_brown", {0.737255, 0.560784, 0.560784},
  "rosy_brown1", {1, 0.756863, 0.756863},
  "rosy_brown2", {0.933333, 0.705882, 0.705882},
  "rosy_brown3", {0.803922, 0.607843, 0.607843},
  "rosy_brown4", {0.545098, 0.411765, 0.411765},
  "saddle_brown", {0.545098, 0.270588, 0.0745098},
  "salmon", {0.435294, 0.258824, 0.258824},
  "salmon0", {0.980392, 0.501961, 0.447059},
  "salmon1", {1, 0.54902, 0.411765},
  "sandy_brown", {0.956863, 0.643137, 0.376471},
  "sea_green", {0.137255, 0.556863, 0.419608},
  "seashell", {1, 0.960784, 0.933333},
  "seashell1", {1, 0.960784, 0.933333},
  "seashell2", {0.933333, 0.898039, 0.870588},
  "seashell3", {0.803922, 0.772549, 0.74902},
  "seashell4", {0.545098, 0.52549, 0.509804},
  "sienna", {0.556863, 0.419608, 0.137255},
  "sienna0", {0.627451, 0.321569, 0.176471},
  "sky_blue", {0.529412, 0.807843, 0.921569},
  "sky_blue1", {0.529412, 0.807843, 1},
  "sky_blue2", {0.494118, 0.752941, 0.933333},
  "sky_blue3", {0.423529, 0.65098, 0.803922},
  "slate_blue", {0.415686, 0.352941, 0.803922},
  "slate_blue1", {0.513725, 0.435294, 1},
  "slate_blue2", {0.478431, 0.403922, 0.933333},
  "slate_blue3", {0.411765, 0.34902, 0.803922},
  "slate_gray", {0.439216, 0.501961, 0.564706},
  "slate_gray1", {0.776471, 0.886275, 1},
  "slate_gray2", {0.72549, 0.827451, 0.933333},
  "slate_gray3", {0.623529, 0.713725, 0.803922},
  "slate_gray4", {0.423529, 0.482353, 0.545098},
  "slate_grey", {0.439216, 0.501961, 0.564706},
  "snow", {1, 0.980392, 0.980392},
  "snow1", {1, 0.980392, 0.980392},
  "snow2", {0.933333, 0.913725, 0.913725},
  "snow3", {0.803922, 0.788235, 0.788235},
  "snow4", {0.545098, 0.537255, 0.537255},
  "spring_green", {0, 1, 0.498039},
  "steel_blue", {0.137255, 0.419608, 0.556863},
  "tan", {0.823529, 0.705882, 0.54902},
  "tan0", {0.858824, 0.576471, 0.439216},
  "thistle", {0.847059, 0.74902, 0.847059},
  "thistle1", {1, 0.882353, 1},
  "thistle2", {0.933333, 0.823529, 0.933333},
  "thistle3", {0.803922, 0.709804, 0.803922},
  "thistle4", {0.545098, 0.482353, 0.545098},
  "tomato", {1, 0.388235, 0.278431},
  "turquoise", {0.678431, 0.917647, 0.917647},
  "violet", {0.309804, 0.184314, 0.309804},
  "violet0", {0.933333, 0.509804, 0.933333},
  "violet_red", {0.8, 0.196078, 0.6},
  "violet_red0", {0.815686, 0.12549, 0.564706},
  "violet_red1", {1, 0.243137, 0.588235},
  "violet_red2", {0.933333, 0.227451, 0.54902},
  "violet_red3", {0.803922, 0.196078, 0.470588},
  "wheat", {0.847059, 0.847059, 0.74902},
  "wheat0", {0.960784, 0.870588, 0.701961},
  "wheat1", {1, 0.905882, 0.729412},
  "wheat2", {0.933333, 0.847059, 0.682353},
  "wheat3", {0.803922, 0.729412, 0.588235},
  "wheat4", {0.545098, 0.494118, 0.4},
  "white", {1, 1, 1},
  "white0", {0.988235, 0.988235, 0.988235},
  "white_smoke", {0.960784, 0.960784, 0.960784},
  "yellow", {1, 1, 0},
  "yellow_green", {0.603922, 0.803922, 0.196078}
};

static int
binary_search(name, l, h, array)
  char           *name;
  int             l, h;
  color_struct    array[];
{
  int             m, result;

  if (l > h)
    return (-1);

  m = (l + h) / 2;

  result = strcmp(name, colors[m].name);
  if (result == 0)
    return m;
  if (result < 0)
    return binary_search(name, l, m - 1, array);
  else
    return binary_search(name, m + 1, h, array);
}

boolean
find_color_by_name(name, color)
  char           *name;
  rgb_ptr         color;
{
  int             result;

  result = binary_search(name, 0, COLORS - 1, colors);
  if (result < 0)
    return FALSE;
  STRUCT_ASSIGN(*color, colors[result].color);
  return TRUE;
}