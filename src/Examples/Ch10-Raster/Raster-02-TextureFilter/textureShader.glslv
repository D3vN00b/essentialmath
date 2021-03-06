// Copyright (C) 2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

layout(location = POSITION) in vec4 position;
layout(location = TEXCOORD0) in vec2 texCoord0;

uniform mat4 IvModelViewProjectionMatrix;

out vec2 uv;

void main()
{
    gl_Position = IvModelViewProjectionMatrix * position;
    uv = texCoord0.xy;
}
