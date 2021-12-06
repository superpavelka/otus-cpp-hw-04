#include "observer.h"
#include "model.h"
#include "controller.h"
#include "view.h"

int main()
{
	std::shared_ptr<Model> model = Model::create();
    std::shared_ptr<Controller> controller = Controller::create(model);
	std::shared_ptr<GUIView> gui_view = GUIView::create(model, controller);	

    gui_view->createNewFile();

    gui_view->addLine({0.0f ,0.0f}, 1.5f);
    gui_view->addLine({-1.0f, -1.0f}, 2.3f);
    gui_view->addLine({-5.0f, 0.0f}, 5.0f);

    gui_view->addEllipse({ 3.0f, 0.0f }, 3.0f, 4.0f);
    
    gui_view->addRectangle({1.0f, 2.0f}, 3.3f, 4.4f);
    gui_view->addRectangle({ 5.0f, 6.0f }, 3.3f, 4.4f);

    gui_view->removeShapeByIndex(1);
    gui_view->removeShapeByIndex(2);

    gui_view->exportToFile("myFirstGraphicProject.grp");
    gui_view->importFromFile("myFirstGraphicProject2.grp");

	return 0;
}