//
// Created by Marti on 4/24/2024.
//

#include "lightning.h"
#include "engine.h"
Lightning::Lightning(Vec position): position{position}{}

void Lightning::execute(Engine& engine) {
    if (frame_count == 0){
        sprite = engine.graphics.get_animated_sprite("lightning");
        //event::number_of_frames matches the animation number of frames
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update();
}