#include "Gerenciador.h"
#include <fstream>


void Gerenciador::comandos(Grafo* grafo) {
    cout<<"Digite uma das opcoes abaixo e pressione enter:"<<endl<<endl;
    cout<<"(a) Fecho transitivo direto de um no;"<<endl;
    cout<<"(b) Fecho transitivo indireto de um no;"<<endl;
    cout<<"(c) Caminho minimo (Djikstra);"<<endl;
    cout<<"(d) Caminho minimo (Floyd);"<<endl;
    cout<<"(e) Arvore Geradora Minima (Algoritmo de Prim);"<<endl;
    cout<<"(f) Arvore Geradora Minima (Algoritmo de Kruskal);"<<endl;
    cout<<"(g) Arvore de caminhamento em profundidade;"<<endl;
    cout<<"(h) Raio, diametro, centro e periferia do grafo;"<<endl;
    cout<<"(0) Sair;"<<endl<<endl;

    char resp;
    cin >> resp;
    switch (resp) {
        case 'a': {

            char id_no = get_id_entrada();
            vector<char> fecho_transitivo_direto = grafo->fecho_transitivo_direto(id_no);
            
            cout << "Fecho transitivo direto do no " << id_no << ": " << endl;
            cout << "{";
            for(const char& id : fecho_transitivo_direto) {
                cout<<id<<", ";
            }
            cout<<"}"<<endl<<endl;

            if(pergunta_imprimir_arquivo("fecho_trans_dir.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl<<endl;
            }

            break;
        }

        case 'b':{

            char id_no = get_id_entrada();
            vector<char> fecho_transitivo_indireto = grafo->fecho_transitivo_indireto(id_no);
            
            cout << "Fecho transitivo indireto do no " << id_no << ": " << endl;
            cout << "{";
            for(const char& id : fecho_transitivo_indireto) {
                cout<<id<<", ";
            }
            cout<<"}"<<endl<<endl;

            if(pergunta_imprimir_arquivo("fecho_trans_indir.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
            }

;
            break;
        }

        case 'c': {

            char id_no_1 = get_id_entrada();
            char id_no_2 = get_id_entrada();
            vector<char> caminho_minimo_dijkstra = grafo->caminho_minimo_dijkstra(id_no_1,id_no_2);
            
            cout << "Caminho minimo entre " << id_no_1 << " e " << id_no_2 << ": " << endl;
            cout << "{";
            for(const char& id : caminho_minimo_dijkstra) {
                cout<<id<<", ";
            }
            cout<<"}"<<endl<<endl;

            if(pergunta_imprimir_arquivo("caminho_minimo_dijkstra.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
            }


            break;
        }

        case 'd': {

            char id_no_1 = get_id_entrada();
            char id_no_2 = get_id_entrada();
            vector<char> caminho_minimo_floyd = grafo->caminho_minimo_floyd(id_no_1,id_no_2);
            cout<<"Metodo de impressao em tela nao implementado"<<endl<<endl;

            if(pergunta_imprimir_arquivo("caminho_minimo_floyd.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
            }


            break;
        }
        case 'e': {

            int tam;
            cout<<"Digite o tamanho do subconjunto: ";
            cin>>tam;

            if(tam > 0 && tam <= grafo->ordem) {

                vector<char> ids = get_conjunto_ids(grafo,tam);
                Grafo* arvore_geradora_minima_prim = grafo->arvore_geradora_minima_prim(ids);
                cout<< "Arvore geradora minima pelo método de Prim: " << endl;
                cout << arvore_geradora_minima_prim->toString() << endl;

                if(pergunta_imprimir_arquivo("agm_prim.txt")) {
                    cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
                }

                delete arvore_geradora_minima_prim;

            }else {
                cout<<"Valor invalido"<<endl;
            }

            break;
        }

        case 'f': {

            int tam;
            cout<<"Digite o tamanho do subconjunto: ";
            cin>>tam;

            if(tam > 0 && tam <= grafo->ordem) {

                vector<char> ids = get_conjunto_ids(grafo,tam);
                Grafo* arvore_geradora_minima_kruskal = grafo->arvore_geradora_minima_kruskal(ids);
                cout << "Arvore geradora minima pelo método de Kruskal: ";
                cout << arvore_geradora_minima_kruskal->toString() << endl;

                if(pergunta_imprimir_arquivo("agm_kruskal.txt")) {
                    cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
                }

                delete arvore_geradora_minima_kruskal;

            }else {
                cout<<"Valor invalido"<<endl;
            }

            break;
        }

        case 'g': {

            char id_no = get_id_entrada();
            Grafo* arvore_caminhamento_profundidade = grafo->arvore_caminhamento_profundidade(id_no);
            cout<<"Metodo de impressao em tela nao implementado"<<endl<<endl;

            if(pergunta_imprimir_arquivo("arvore_caminhamento_profundidade.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
            }

            delete arvore_caminhamento_profundidade;
            break;
        }

        case 'h': {
            vector<char> articulacao = grafo->vertices_de_articulacao();
            cout<<"Metodo de impressao em tela nao implementado"<<endl<<endl;

            if(pergunta_imprimir_arquivo("arvore_caminhamento_profundidade.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
            }

            break;
        }
        case 'i': {

            vector<char> articulacao = grafo->vertices_de_articulacao();
            cout<<"Metodo de impressao em tela nao implementado"<<endl<<endl;

            if(pergunta_imprimir_arquivo("arvore_caminhamento_profundidade.txt")) {
                cout<<"Metodo de impressao em arquivo nao implementado"<<endl;
            }

            break;
        }

        case '0': {
            exit(0);
        }
        default: {
            cout<<"Opção inválida"<<endl;
        }
    }

    comandos(grafo);

}

char Gerenciador::get_id_entrada() {
    cout<<"Digite o id de um no: ";
    char id;
    cin>>id;
    cout<<endl;
    return id;
}

vector<char> Gerenciador::get_conjunto_ids(Grafo *grafo, int tam) {
    vector<char> ids = {};
    while((int)ids.size() < tam) {
        char id_no =get_id_entrada();
        bool existe = false;
        for(No* no: grafo->lista_adj){
            if(no->id == id_no){
                existe = true;
                break;
            }
        }

        if(!existe){
            cout<<"Vertice nao existe"<<endl;
        }else{
            bool repetido = find(ids.begin(), ids.end(),id_no) != ids.end();
            if(repetido) {
                    cout<<"Valor repetido"<<endl;
            }else {
                ids.push_back(id_no);
            }
        }

    }

    return ids;
}


bool Gerenciador::pergunta_imprimir_arquivo(string nome_arquivo) {

    cout<<"Imprimir em arquivo externo? ("<<nome_arquivo<<")"<<endl;
    cout<<"(1) Sim;"<<endl;
    cout<<"(2) Nao."<<endl;
    int resp;
    cin>>resp;
    cout<<endl;

    switch (resp) {
        case 1:
            return true;
        case 2:
            return false;
        default:
            cout<<"Resposta invalida"<<endl;
            return pergunta_imprimir_arquivo(nome_arquivo);
    }
}

#include "Gerenciador.h"

// MÉTODO NOVO
Grafo* Gerenciador::carregarGrafoDoArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        throw std::runtime_error("Erro ao abrir: " + nomeArquivo);
    }

    // Lê dados da linha 1
    bool direcionado, ponderadoVertices, ponderadoArestas;
    if (!(arquivo >> direcionado >> ponderadoArestas >> ponderadoVertices)) {
        throw std::runtime_error("Formato inválido na linha 1");
    }

    // Criar o grafo e setar propriedades
    Grafo* grafo = new Grafo();
    grafo->in_direcionado = direcionado;
    grafo->in_ponderado_vertice = ponderadoVertices;
    grafo->in_ponderado_aresta = ponderadoArestas;

    // Lê número de vértices (linha 2)
    int numVertices;
    if (!(arquivo >> numVertices) || numVertices <= 0) {
        delete grafo;
        throw std::runtime_error("Número de vértices inválido");
    }
    grafo->ordem = numVertices;

    // Lê vértices
    char id;
    int peso;
    for (int i = 0; i < numVertices; i++) {
        if (ponderadoVertices) {
            if (!(arquivo >> id >> peso)) {
                delete grafo;
                throw std::runtime_error("Erro ao ler vértice " + std::to_string(i+1));
            }
        } else {
            if (!(arquivo >> id)) {
                delete grafo;
                throw std::runtime_error("Erro ao ler vértice " + std::to_string(i+1));
            }
            peso = 0; // Peso padrão para vértices não ponderados
        }
        
        // Criar e adicionar vértice
        No* novoNo = new No(id, peso);
        grafo->lista_adj.push_back(novoNo);
    }

    // Lê arestas
    std::string linha;
    std::getline(arquivo, linha); // Consumir a quebra de linha restante
    
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        
        std::istringstream iss(linha);
        char origem, destino;
        int pesoAresta = 1; // Default para grafos não ponderados
        
        if (!(iss >> origem >> destino)) {
            delete grafo;
            throw std::runtime_error("Formato inválido de aresta: " + linha);
        }
        
        if (ponderadoArestas && !(iss >> pesoAresta)) {
            delete grafo;
            throw std::runtime_error("Peso faltando em aresta: " + linha);
        }

        // Encontrar nó de origem na lista
        auto it = std::find_if(grafo->lista_adj.begin(), grafo->lista_adj.end(), 
            [&](No* no) { return no->getID() == origem; });
        
        if (it == grafo->lista_adj.end()) {
            delete grafo;
            throw std::runtime_error("Vértice de origem não encontrado: " + std::string(1, origem));
        }
        
        // Adicionar aresta
        Aresta* novaAresta = new Aresta(destino, pesoAresta);
        (*it)->adicionarAresta(novaAresta);
        
        // Se o grafo não for direcionado, precisamos adicionar a aresta inversa também
        // para que o grafo seja simétrico.
        if (!direcionado) {
            // Primeiro, encontramos o nó de destino na lista de nós.
            auto it_dest = std::find_if(grafo->lista_adj.begin(), grafo->lista_adj.end(),
                [&](No* no) { return no->getID() == destino; });
            
            // Se o nó de destino não for encontrado, lançamos uma exceção.
            if (it_dest == grafo->lista_adj.end()) {
                delete grafo;
                throw std::runtime_error("Vertice de destino nao encontrado: " + std::string(1, destino));
            }
            
            // Agora, adicionamos a aresta inversa ao nó de destino.
            Aresta* arestaInversa = new Aresta(origem, pesoAresta);
            (*it_dest)->adicionarAresta(arestaInversa);
        }
    }

    return grafo;
}

