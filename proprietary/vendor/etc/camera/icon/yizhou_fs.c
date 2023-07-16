#version 300 es

precision highp float;
in vec2 vTexCoor;

uniform float width;
uniform float height;
uniform int angle;

uniform sampler2D sTexture;
uniform sampler2D sBlurTexture;

out vec4 uFragColor;

void main() {

    
    vec4 originColor = texture(sTexture, vTexCoor);
    vec4 blurColor = texture(sBlurTexture, vTexCoor);
    vec2 finalTexCoor= vTexCoor.st;
    if (finalTexCoor.s < 0.25 || finalTexCoor.s > 0.75) {
        uFragColor = blurColor;
    } else if (finalTexCoor.s <= 0.35) {
        uFragColor =
            ((0.35f - finalTexCoor.s) / 0.1) * blurColor +
            ((finalTexCoor.s - 0.25) / 0.1) * originColor;
    } else if (finalTexCoor.s >= 0.65) {
        uFragColor =
            ((finalTexCoor.s - 0.65) / 0.1) * blurColor + ((0.75 - finalTexCoor.s) / 0.1) * originColor;
    } else {
        uFragColor = originColor;
    }
}
