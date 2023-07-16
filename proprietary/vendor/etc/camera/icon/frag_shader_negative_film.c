#version 300 es

precision mediump float;
in vec2 vTexCoor;
uniform sampler2D sTexture;
out vec4 uFragColor;

void main() {
    vec4 color = texture(sTexture, vTexCoor);

    uFragColor = vec4(1.0 - color.r, 1.0 - color.g, 1.0 - color.b, color.a);
}
