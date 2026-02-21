
/* Jenova C++ Node Base Script (Meteora) */

// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/node.hpp>
#include <Godot/variant/variant.hpp>
#include <Godot/classes/node2d.hpp>
#include <Godot/classes/label.hpp>
#include <Godot/classes/button.hpp>

#include <JenovaSDK.h>

// Namespaces
using namespace godot;
using namespace jenova::sdk;

// Self Instance
Node* self = nullptr;

// Jenova Script Block Start
JENOVA_SCRIPT_BEGIN


JENOVA_PROPERTY(int, score, 0);
JENOVA_PROPERTY(String, labelText, "", Group:"label stuff");
JENOVA_PROPERTY(int, dummy_state, 0, Hint:PROPERTY_HINT_ENUM, HintString:"Idle, Walk, Run, Crouch");

void OnReady(Caller* instance) {
	// %i steht für integer
	Output("instance ready\t%i", score);

	auto self = (Node2D*)instance -> self;
	Output(GetCStr(self -> get_name()));

	auto myLabel = GetNode<Label>("Test123/GUI/Label");
	myLabel -> set_text(labelText);

	auto myButton = GetNode<Button>("Test123/GUI/Button");
	myButton -> set_text("Drück mich endlich!");

}

void _on_button_pressed() {

	auto label = GetNode<Label>("Test123/GUI/Label");

	score++;
	if (score >= 20) {
		label -> set_text("Junge hast du langeweile?");
	} else {
		// itos = int to string
		//label -> set_text(itos(score));
		label -> set_text(String::num_int64(score));
	}
	Output("%i", score);
}

// Jenova Script Block End
JENOVA_SCRIPT_END
