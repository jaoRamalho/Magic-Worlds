#include "../include/Gerenciadores/GerenciadorGrafico.hpp"
#include"../include/Ente/Ente.hpp"

GR::GerenciadorGrafico* GR::GerenciadorGrafico::instancia = nullptr; 

GR::GerenciadorGrafico::GerenciadorGrafico(){
    pImagens = GR::GerenciadorImagens::getInstancia();
    janela = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Game", sf::Style::Fullscreen);
    fonte = new sf::Font();

    camera = janela->getDefaultView();
    camera.setSize(sf::Vector2f(janela->getSize()));
    camera.setCenter(camera.getSize()/2.f);
    janela->setView(camera);
    janela->setFramerateLimit(25);
    fonte->loadFromFile("utilits/alagard.ttf");

}

GR::GerenciadorGrafico::~GerenciadorGrafico(){
    delete janela;
    delete fonte;
}

GR::GerenciadorGrafico* GR::GerenciadorGrafico::getInstancia(){
    if(instancia == nullptr)
        instancia = new GerenciadorGrafico(); 

    return instancia;
}

void GR::GerenciadorGrafico::fecharJanela(){
    if(janelaAberta()) { janela->close(); }
}

const bool GR::GerenciadorGrafico::janelaAberta() const {
    return janela->isOpen(); 
}

void GR::GerenciadorGrafico::limpar(){
    if(janelaAberta()) 
        janela->clear(); 
}

void GR::GerenciadorGrafico::mostrar(){
    if(janelaAberta()) 
        janela->display(); 
}

void GR::GerenciadorGrafico::desenhar(Ente* ent){
    ent->desenhar();
}
