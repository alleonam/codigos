/*
 * Guia01 - v1.E3. - 17 / 02 / 2023
 * Author: Manoella Santos Diniz
 */

// lista de dependencias
#include "karel.hpp"
#include "myKarel.hpp"

// --------------------------- definicoes de metodos

/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    int i;

    // colocar paredes no mundo
    for (i = 3; i < 6; i++)
    {
        world->set(i, 2, HWALL);
        world->set(i, 6, HWALL);
        world->set(5, i, VWALL);
    }

    for (i = 3; i < 7; i++)
    {
        world->set(2, i, VWALL);
    }

    // colocar um marcador no mundo
    for (i = 0; i < 6; i++)
    {
        world->set(4, 3, BEEPER);
    }

    // salvar a configuracao atual do mundo
    world->save(fileName);
}

// --------------------------- acao principal

/**
 * Acao principal: executar a tarefa descrita acima.
 */
int main()
{
    // definir o contexto

    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    //       antes de qualquer outra coisa
    //       (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia01E3.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia01E3.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual

    set_Speed(3); // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();

    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");

    // executar tarefa
    robot->doTask();

    // encerrar operacoes no ambiente
    world->close();

    // encerrar programa
    getchar();
    return (0);
}

// ------------------------------------------- testes

/*
 *
 * ---------------------------------------------- documentacao complementar
 *
 * ---------------------------------------------- notas / observacoes / comentarios
 *
 * ---------------------------------------------- previsao de testes
 *
 * v1.1 - 01. o robo ira deslocar e colocar os
 *            marcadores de acordo com as repeticoes
 *
 * v1.2 - 01. o robo ira deslocar e pegar os
 *            marcadores de acordo com as repeticoes
 *
 * v1.3 - 01. o robo ira deslocar, pegar os
 *            marcadores de acordo com as repeticoes
 *            e colocar nos pontos definidos
 *
 * v1.4 - 01. o robo ira deslocar, desviar das
 *            paredes e pegar o marcador
 *
 * v1.5 - 01. o robo ira deslocar, desviar das
 *            paredes, pegar os marcadores e
 *            colocar nas posicoes indicadas
 *
 * v1.E1 - 01. o robo ira deslocar, desviar das
 *             paredes, pegar os marcadores e
 *             colocar nas posicoes indicadas
 *         02. se os marcadores nao forem
 *             suficientes, o robo nao ira
 *             pega-los
 *         03. mesmo que tenha marcadores sobrando,
 *             o robo ira deixa-los para tras
 *
 * v1.E2 - 01. o robo fara as mesmas acoes
 *             definidas no programa anterior
 *
 * ---------------------------------------------- historico
 *
 * Versao   Data    Modificacao
 * 0.1      16/02   esboco
 * 0.2      16/02   adicao do metodo doTask()
 * 0.3      16/02   adicao do metodo doPartialTask()
 * 0.4      16/02   adicao do metodo pickBeeper()
 * 0.5      16/02   adicao do metodo putBeeper()
 * 0.6      16/02   adicao do metodo moveN()
 * 0.7      16/02   testes dos marcadores com o metodo beepersInBag()
 * 0.8      16/02   teste com quantidade
 * 0.9      16/02   adicao de while() para a repeticao do movimento
 * 1.0      16/02   adicao de for() para a repeticao do movimento
 * 1.1      16/02   novo conjunto de acoes
 * 1.2      16/02   novo conjunto de acoes
 * 1.3      16/02   novo conjunto de acoes
 * 1.4      16/02   criacao de uma caixa
 * 1.5      16/02   caixa com mais marcadores
 * 1.E1     16/02   procedimentos para pegar varios marcadores
 * 1.E2     16/02   repeticoes com variacoes crescentes
 * 1.E3     16/02   reuniao das definicoes feitas em MyRobot
 *
 * ---------------------------------------------- testes
 *
 * Versao   Teste
 * 0.1      01. ( OK )  teste inicial
 * 0.2      01. ( OK )  teste da tarefa
 * 0.3      01. ( OK )  teste da tarefa parcial
 * 0.4      01. ( OK )  teste do apanhar marcador
 * 0.5      01. ( OK )  teste do colocar marcador
 * 0.6      01. ( OK )  teste da repeticao do movimento
 * 0.7      01. ( OK )  teste com marcador na posicao (4, 4)
 *          02. ( OK )  teste sem marcador na posicao (4, 4)
 * 0.8      01. ( OK )  teste com a quantidade de marcadores
 * 0.9      01. ( OK )  teste com outra forma de repeticao
 * 1.0      01. ( OK )  teste com outra forma de alternativa
 * 1.1      01. ( OK )  teste das novas acoes
 * 1.2      01. ( OK )  teste das novas acoes
 * 1.3      01. ( OK )  teste das novas acoes
 * 1.4      01. ( OK )  teste da caixa
 * 1.5      01. ( OK )  teste da caixa com multiplos marcadores
 * 1.E1     01. ( OK )  teste dos procedimentos putBeepers() e pickBeepers()
 *          02. ( OK )  teste de tentar pegar mais marcadores
 *          03. ( OK )  teste de pegar menos marcadores
 * 1.E2     01. ( OK )  teste das variacoes crescentes
 * 1.E3     01. ( OK )  teste do myKarel
 *
 */
