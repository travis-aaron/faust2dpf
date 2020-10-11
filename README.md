# faust2dpf

This is a small project meant as a way to facilitate the creation of UIs from Faust functional programming language, through the Distrho plugin framework.

While Faust can export to VST or LV2 natively, adding a UI complicates the issue by an order of magnitude. Faust natively allows the use of QT, but Linux native DAWs such as Ardour and Mixbus don't support this as they believe plugins should be self-sufficient and not to depend on external libraries (rightfully so.) Distrho has templates and examples to showcase various types of UI such as Cairo, NanoVG, and OpenGL.

### Why use Faust at all?

It's true, using Faust complicates this, and plugins can be made using Distrho alone. However, Faust allows a quick workflow, excellent for prototyping, which is crucial for those of us finding our footing with DSP. Furthermore, the idea of separating the creation of the DSP and UI side of the plugin is something that really appeals.
