SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

DROP SCHEMA IF EXISTS `apasoftwarer` ;
CREATE SCHEMA IF NOT EXISTS `apasoftwarer` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
SHOW WARNINGS;
USE `apasoftwarer` ;

-- -----------------------------------------------------
-- Table `conductores`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `conductores` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `conductores` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombreconductor` VARCHAR(150) NOT NULL ,
  `cedulaconductor` VARCHAR(45) NOT NULL ,
  `nombrepropietario` VARCHAR(150) NOT NULL ,
  `cedulapropietario` VARCHAR(45) NOT NULL ,
  `direccionpropietario` VARCHAR(800) NOT NULL ,
  `telefono` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `marca`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `marca` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `marca` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `modelo`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `modelo` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `modelo` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  `marca_id` INT NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `tipo`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `tipo` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `tipo` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `color`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `color` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `color` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `seguro`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `seguro` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `seguro` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(100) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `uso`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `uso` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `uso` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `vehiculo`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `vehiculo` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `vehiculo` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `serialcarroceria` VARCHAR(80) NOT NULL ,
  `serialmotor` VARCHAR(80) NOT NULL ,
  `numeropoliza` VARCHAR(80) NOT NULL ,
  `placa` VARCHAR(45) NOT NULL ,
  `anho` YEAR NOT NULL ,
  `marca_id` INT NOT NULL ,
  `modelo_id` INT NOT NULL ,
  `tipo_id` INT NOT NULL ,
  `color_id` INT NOT NULL ,
  `seguro_id` INT NOT NULL ,
  `uso_id` INT NOT NULL ,
  `conductores_id` INT NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `perito`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `perito` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `perito` (
  `id` INT NOT NULL ,
  `nombre` VARCHAR(45) NOT NULL ,
  `apellido` VARCHAR(45) NOT NULL ,
  `profesion` VARCHAR(45) NULL ,
  `cedula` VARCHAR(45) NOT NULL ,
  `unidad` VARCHAR(45) NOT NULL ,
  `codigo` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `accidente`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `accidente` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `accidente` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `direccion` VARCHAR(300) NOT NULL ,
  `fecha` DATE NOT NULL ,
  `hora` VARCHAR(45) NOT NULL ,
  `monto` VARCHAR(100) NOT NULL ,
  `vehiculo_id` INT NOT NULL ,
  `perito_id` INT NOT NULL ,
  `montoletra` VARCHAR(300) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `tipoautoparte`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `tipoautoparte` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `tipoautoparte` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `autopartes`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `autopartes` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `autopartes` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(100) NOT NULL ,
  `tipoautoparte_id` INT NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `accidentesautoparte`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `accidentesautoparte` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `accidentesautoparte` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `autoparte_id` INT NOT NULL ,
  `accidente_id` INT NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `direccionrevision`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `direccionrevision` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `direccionrevision` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `lugar` VARCHAR(1000) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `ciudadinspeccion`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `ciudadinspeccion` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `ciudadinspeccion` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `avaluo`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `avaluo` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `avaluo` (
  `id` VARCHAR(45) NOT NULL ,
  `expediente` VARCHAR(45) NULL ,
  `direccionrevision_id` INT NOT NULL ,
  `fecha` DATE NOT NULL ,
  `accidente_id` INT NOT NULL ,
  `ciudadinspeccion_id` INT NOT NULL ,
  `numeroplanilla` VARCHAR(100) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `encabezado`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `encabezado` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `encabezado` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `cabecera` VARCHAR(200) NOT NULL ,
  `primeraparte` VARCHAR(300) NOT NULL ,
  `nombre` VARCHAR(45) NOT NULL ,
  `segundaparte` VARCHAR(300) NOT NULL ,
  `cedula` VARCHAR(50) NOT NULL ,
  `terceraparte` VARCHAR(1000) NOT NULL ,
  `codigo` VARCHAR(45) NOT NULL ,
  `cuartaparte` VARCHAR(1000) NOT NULL ,
  `titulo` VARCHAR(300) NOT NULL ,
  `quintaparte` VARCHAR(1000) NOT NULL ,
  `sitio` VARCHAR(50) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `reporte`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `reporte` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `reporte` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombreconductor` VARCHAR(100) NOT NULL ,
  `cedulaconductor` VARCHAR(100) NOT NULL ,
  `nombrepropietario` VARCHAR(100) NULL ,
  `cedulapropietario` VARCHAR(100) NULL ,
  `telefono` VARCHAR(100) NULL ,
  `direccion` VARCHAR(1000) NULL ,
  `marca` VARCHAR(100) NULL ,
  `modelo` VARCHAR(100) NULL ,
  `tipo` VARCHAR(100) NULL ,
  `anho` VARCHAR(100) NULL ,
  `color` VARCHAR(45) NULL ,
  `placa` VARCHAR(45) NULL ,
  `carroceria` VARCHAR(1000) NULL ,
  `motor` VARCHAR(1000) NULL ,
  `seguro` VARCHAR(100) NULL ,
  `poliza` VARCHAR(100) NULL ,
  `uso` VARCHAR(100) NULL ,
  `fechaavaluo` VARCHAR(100) NULL ,
  `experticia` VARCHAR(1000) NULL ,
  `expediente` VARCHAR(1000) NULL ,
  `hora` VARCHAR(100) NULL ,
  `montonumero` VARCHAR(500) NULL ,
  `fechaaccidente` VARCHAR(100) NULL ,
  `diraccidente` VARCHAR(1000) NULL ,
  `dirrevision` VARCHAR(1000) NULL ,
  `piezascambio` VARCHAR(1000) NULL ,
  `piezasreparar` VARCHAR(1000) NULL ,
  `observacion` VARCHAR(1000) NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `observaciones`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `observaciones` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `observaciones` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nota` VARCHAR(800) NOT NULL ,
  `avaluo_id` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `code`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `code` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `code` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `codigo` VARCHAR(1000) NOT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = MyISAM;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `perito_code`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `perito_code` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `perito_code` (
  `idperito_code` INT NOT NULL AUTO_INCREMENT ,
  `nombreempresa` VARCHAR(1000) NOT NULL ,
  `perito_id` INT NOT NULL ,
  `code_id` INT NOT NULL ,
  PRIMARY KEY (`idperito_code`) )
ENGINE = MyISAM;

SHOW WARNINGS;
USE `apasoftwarer` ;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

-- -----------------------------------------------------
-- Data for table `tipoautoparte`
-- -----------------------------------------------------
START TRANSACTION;
USE `apasoftwarer`;
INSERT INTO `tipoautoparte` (`id`, `nombre`) VALUES (1, 'Cambiar');
INSERT INTO `tipoautoparte` (`id`, `nombre`) VALUES (2, 'reparar');

COMMIT;

-- -----------------------------------------------------
-- Data for table `autopartes`
-- -----------------------------------------------------
START TRANSACTION;
USE `apasoftwarer`;
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (1, 'Filtro/Secador-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (2, 'Antena/Radio-AM/FM', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (3, 'Colector/Aire', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (4, 'Aro/Faro-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (5, 'Aro/Faro-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (6, 'Aros/faros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (7, 'Compresor-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (8, 'Condensador-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (9, 'Guardapolvo/Rueda-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (10, 'Guardapolvo/Rueda-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (11, 'Guardapolvos/Ruedas-Delanteras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (12, 'Electrov-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (13, 'Electrov-Enf/Motor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (14, 'Aspa/Ventilador-Enf/Motor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (15, 'Fanclouch', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (16, 'Filler', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (17, 'Filler/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (18, 'Filler/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (19, 'Bater�a', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (20, 'Base/Bater�a', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (21, 'Manguera/Radiador-Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (22, 'Manguera/Radiador-Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (23, 'Mangueras/Radiador-Inferior/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (24, 'Bomba/Agua', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (25, 'Bomba/Direccion-Hidr�ulica', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (26, 'Motor/Arranque', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (27, 'Alternador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (28, 'Dinamo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (29, 'Turbo/Compresor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (30, 'Turbina/Enf-Motor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (31, 'Evaporador-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (32, 'Carburador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (33, 'Cuerpo/Inyecci�n', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (34, 'Bobina/Encendido', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (35, 'Tapa/Distribuci�n-Encendido', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (36, 'Distribuidor/Encendido', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (37, 'Caucho/Radial', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (38, 'Caucho/Convencional', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (39, 'Caucho/Tacos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (40, 'Cruce/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (41, 'Cruce/izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (42, 'Cruces-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (43, 'Faros/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (44, 'Faro/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (45, 'Faros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (46, 'Deposito/Agua-Lpb', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (47, 'Deposito/Agua-Radiador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (48, 'Deposito/Fluido-Frenos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (49, 'Purificador/Aire', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (50, 'Ducto/Purificador-Aire', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (51, 'Rin/Basico', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (52, 'Rin/Lujo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (53, 'Volante/Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (54, 'Columna/Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (55, 'Fusiblera/Externa', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (56, 'Fusiblera/Interna', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (57, 'Parabrisa/Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (58, 'Parabrisa/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (59, 'Vidrio/Compuerta-Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (60, 'Vidrio/Techo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (61, 'Tapizado/Techo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (62, 'Tapizado/Interno-Compuerta/Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (63, 'Alfombra/Piso', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (64, 'Alfombra/Maletero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (65, 'Taza/Rueda', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (66, 'Tuber�a-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (67, 'Tuber�a/Frenos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (68, 'Repisa/Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (69, 'Vidrio/Puerta-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (70, 'Vidrio/Puerta-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (71, 'Vidrios/Puertas-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (72, 'Vidrio/Puerta-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (73, 'Vidrio/Puerta-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (74, 'Vidrios/Puertas-Delanteras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (75, 'Vidrio/Puerta-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (76, 'Vidrio/Puerta-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (77, 'Vidrios/Puertas-Traseras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (78, 'Vidrio/Guard-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (79, 'Vidrio/Guard-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (80, 'Vidrios/Guard-Traseros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (81, 'Air/Bag-Volante/Conductor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (82, 'Air/Bag-Tablero/Moldura', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (83, 'Sensores/Delanteros-Air/Bag', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (84, 'Modulo/Air-Bag', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (85, 'Modulo/ABS', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (86, 'Cinta/Damero-Taxi', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (87, 'Rotulado/Placas', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (88, 'Rotulado/Publicit�rio', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (89, 'Cinta/Decorativa-Tipo/Madera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (90, 'Calcomania/Decorativa', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (91, 'Corneta/Pito', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (92, 'Corneta/Aire', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (93, 'Emblema/Logo-Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (94, 'Emblemas', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (95, 'Rejilla/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (96, 'Marco/Rejilla-Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (97, 'Marco/Interno-Fibra/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (98, 'Parrilla/Deportiva-Techo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (99, 'Defensa/Deportiva-Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (100, 'Defensa/Deportiva-Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (101, 'Retrovisor/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (102, 'Retrovisor/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (103, 'Retrovisor-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (104, 'Retrov/Electrico-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (105, 'Retrov/Electrico-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (106, 'Retrov/Electrico-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (107, 'Guantera/Tablero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (108, 'Consola/Central', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (109, 'Consola/Techo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (110, 'Stop/Trasero-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (111, 'Stop/Trasero-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (112, 'Stop/Trasero-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (113, 'Stop/Lateral-Der/Maletero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (114, 'Stop/Lateral-Izq/Maletero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (115, 'Stop/Lateral-Maletero-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (116, 'Tacometro/Veloc�metro', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (117, 'Guardafango/Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (118, 'Barras/Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (119, 'Man�brio/Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (120, 'Faro/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (121, 'Careta/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (122, 'Careta/Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (123, 'Careta-Inferior/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (124, 'T/Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (125, 'T/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (126, 'T-Inferior/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (127, 'Manilla/Embrague', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (128, 'Manilla/Freno-Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (129, 'Tanque/Combustible', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (130, 'Marco/Chasis', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (131, 'Posapie/Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (132, 'Posapie/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (133, 'Guardafango/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (134, 'Aro/Rin-Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (135, 'Aro/Rin-Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (136, 'Encadenado/Deportivo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (137, 'Tapa/Protectora-Lateral/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (138, 'Tapa/Protectora-Lateral/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (139, 'Pu�o/Derecho', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (140, 'Pu�o/Izquierdo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (141, 'Pesa/Pu�o-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (142, 'Pesa/Pu�o-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (143, 'Puesto/Asiento', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (144, 'Caucho/Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (145, 'Caucho/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (146, 'Tapa/Lateral-Der/Motor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (147, 'Tapa/Lateral-Izq/Motor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (148, 'Tapa/Cubre-Piernas', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (149, 'Tapa/Guardapolvo-Piso', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (150, 'Tapa/Cubierta-Principal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (151, 'Tapa/Lateral-Inferior/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (152, 'Tapa/Lateral-Inferior/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (153, 'Porta/Placa-Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (154, 'Stop/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (155, 'Swichera/Encendido', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (156, 'Sistema/Alarma-Anti/Robo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (157, 'Cadena/Propulsora', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (158, 'Brazo/Lpb-Delantero/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (159, 'Brazo/Lpb-Delantero/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (160, 'Brazos/Lpb-Delanteros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (161, 'Brazo/Lpb-Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (162, 'Cepillo/Lpb-Delantero/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (163, 'Capillo/Lpb-Delantero/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (164, 'Cepillos/Lpb-Delanteros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (165, 'Cepillo/Lpb-Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (166, 'Motor/Lpb-Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (167, 'Motor/Lpb-Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (168, 'Correa/Multi-Funci�n', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (169, 'Correa/Alternador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (170, 'Correa/Compresor-A/A', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (171, 'Correa/Bomba-Direccion/Hidr�ulica', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (172, 'Catalizador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (173, 'Canister/Gases-Admision', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (174, 'Manilla/Externa-Puerta/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (175, 'Manilla/Externa-Puerta/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (176, 'Manilla/Externa-Puerta/Del-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (177, 'Manilla/Externa-Puerta/Del-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (178, 'Manilla/Externa-Puerta/Tras-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (179, 'Manilla/Externa-Puerta/Tras-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (180, 'Manilla/Externa-Compuerta/Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (181, 'Compuerta/Trasera-Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (182, 'Compuerta/Trasera-Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (183, 'Compuerta/Lateral-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (184, 'Compuerta/Lateral-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (185, 'Compuerta/Trasera-Caj�n/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (186, 'Guard/Der-Caj�n/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (187, 'Guard/Izq-Caj�n/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (188, 'Piso/Caj�n-Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (189, 'Panel/Frontal-Caj�n/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (190, 'Carter/Der-Caj�n/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (191, 'Carter/Izq-Caj�n/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (192, 'Piso/Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (193, 'Carter/Maletero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (194, 'Piso/Maleta', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (195, 'Palanca/Selectora-Lpb', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (196, 'Palanca/Selectora-Luces', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (197, 'Disco/Freno-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (198, 'Disco/Freno-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (199, 'Discos/Frenos-Delanteros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (200, 'Disco/Freno-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (201, 'Disco/Freno-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (202, 'Discos/Frenos-Traseros-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (203, 'Carter/Aceite-Motor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (204, 'Carter/Aceite-Transmisi�n/Autom�tica', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (205, 'Cerradura/Capo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (206, 'Cerradura/Maleta', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (207, 'Cajetin/Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (208, 'Bomba/Frenos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (209, 'Boster/Frenos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (210, 'Bombona/Aire-Frenos/Neumaticos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (211, 'V�lvula/Sistema-Frenos/Neumaticos', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (212, 'Pulmon/Sistema-Freno/Neumatico', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (213, 'Manguera/Frenos-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (214, 'Manguera/Frenos-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (215, 'Tambor/Frenos-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (216, 'Tambor/Frenos-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (217, 'Suspensi�n/Delantera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (218, 'Suspensi�n/Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (219, 'Puente/Suspensi�n-Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (220, 'Puente/Suspensi�n-Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (221, 'Brazo/Axial-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (222, 'Brazo/Axial-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (223, 'Brazo/Axial-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (224, 'Mesta/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (225, 'Meseta/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (226, 'Mesetas-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (227, 'Meseta/Delantera-Der/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (228, 'Meseta/Delantera-Izq/Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (229, 'Meseta/Delantera-Der/Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (230, 'Meseta/Delantera-Izq/Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (231, 'Carcaza/Transmisi�n-Manual', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (232, 'Transmisi�n/Autom�tica-Veloc', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (233, 'Transmisi�n/Manual-Veloc', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (234, 'Tunel/Eje-Diferencial/Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (235, 'Tunel/Eje-Diferencial/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (236, 'Conjunto/Eje-Diferencial/Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (237, 'Conjunto/Eje-Diferencial/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (238, 'Punta/Eje-Delantera/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (239, 'Punta/Eje-Delantera/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (240, 'Punta/Eje-Trasero/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (241, 'Punta/Eje-Trasero/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (242, 'Cardan/Eje-Propulsor', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (243, 'Cardan/Eje-Propulsor/Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (244, 'Cardan/Eje-Propulsor/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (245, 'Tubo/Escape', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (246, 'Silenciador/Escape', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (247, 'Mufle/Resonador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (248, 'Tapizado/Puerta-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (249, 'Tapizado/Puerta-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (250, 'Tapizado/Puerta-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (251, 'Tapizado/Puerta-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (252, 'Tapizado/Puerta-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (253, 'Tapizado/Puerta-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (254, 'Tripoide/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (255, 'Tripoide/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (256, 'Tripoides-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (257, 'Amort/Del-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (258, 'Amort/Del-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (259, 'Amort/Del-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (260, 'Amort/Tras-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (261, 'Amort/Tras-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (262, 'Amort/Tras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (263, 'Suspensi�n/Ballestas-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (264, 'Suspensi�n/Ballestas-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (265, 'Suspensi�n/Ballestas-Traseras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (266, 'Sensor/MAF', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (267, 'Sensor/Oxigeno', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (268, 'Luz/Exploradora-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (269, 'Luz/Exploradora-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (270, 'Luz/Exploradora-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (271, 'Extension/Der-Parach/Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (272, 'Extensi�n/Izq-Parach/Del ', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (273, 'Extensiones/Laterales-Parach/Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (274, 'Extension/Der-Parach/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (275, 'Extension/Izq-Parach/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (276, 'Extensiones/Laterales-Parach/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (277, 'Barra/Estabilizadora-Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (278, 'Barra/Estabilizadora-Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (279, 'Brazo/Pitman-Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (280, 'Barra/tensora-Susp/Del-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (281, 'Barra/tensora-Susp/Del-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (282, 'Barra/tensora-Susp/Tras-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (283, 'Barra/tensora-Susp/Tras-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (284, 'Terminal/Direccion-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (285, 'Terminal/Direccion-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (286, 'Terminal/Direccion-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (287, 'Luz/Placa-Del', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (288, 'Luz/Placa-Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (289, 'Platina/Puerta-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (290, 'Platina/Puerta-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (291, 'Platinas/Puertas-Der-Del/tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (292, 'Platina/Puerta-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (293, 'Platina/Puerta-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (294, 'Platinas/Puertas-Izq-Del/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (295, 'Platina/Guard-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (296, 'Platina/Guard-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (297, 'Platina/Guard-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (298, 'Platina/Guard-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (299, 'Moldura/Interna-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (300, 'Moldura/Interna-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (301, 'Molduras/Internas-Traseras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (302, 'Moldura/Externa-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (303, 'Moldura/Externa-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (304, 'Chapaleta/Rueda-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (305, 'Chapaleta/Rueda-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (306, 'Chapaleta/Rueda-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (307, 'Chapaleta/Rueda-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (308, 'Guardafango/Del-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (309, 'Guardafango/Del-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (310, 'Guardafango/Del-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (311, 'Guardafango/Tras-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (312, 'Guardafango/Tras-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (313, 'Guardafangos/Der-Del/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (314, 'Guardafangos/Izq-Del/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (315, 'Carter/Guardafango-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (316, 'Carter/Guardafango-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (317, 'Carter/Guardafango-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (318, 'Carter/Guardafango-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (319, 'Puerta/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (320, 'Puerta/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (321, 'Puerta/Del-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (322, 'Puerta/Del-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (323, 'Puerta/Tras-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (324, 'Puerta/Tras-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (325, 'Puertas/Der-Del/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (326, 'Puertas/Izq-Del/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (327, 'Babero/Del-Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (328, 'Babero/Tras-Inferior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (329, 'Capo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (330, 'Marco/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (331, 'Marco/Frontal-Superior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (332, 'Cabina', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (333, 'Careta/Capo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (334, 'Extension/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (335, 'Marco/Cabina-Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (336, 'Panel/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (337, 'Panel/Posterior', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (338, 'Extension/Der-Panel/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (339, 'Extension/Izq-Panel/Frontal', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (340, 'Borde/Guard-Del/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (341, 'Borde/Guard-Del/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (342, 'Borde/Guard-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (343, 'Borde/Guard-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (344, 'Borde/Puerta-Tras/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (345, 'Borde/Puerta-Tras/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (346, 'Panel/Lateral-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (347, 'Panel/Lateral-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (348, 'Panel/Lateral-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (349, 'Panel/Lateral-Delantero/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (350, 'Panel/Lateral-Delantero/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (351, 'Panel/Lateral-Central/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (352, 'Panel/Lateral-Central/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (353, 'Panel/Lateral-Posterior/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (354, 'Panel/Lateral-Posterior/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (355, 'Estructura/Interna-Lateral/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (356, 'Estructura/Interna-Lateral/izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (357, 'Estructura/Interna-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (358, 'Parach/Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (359, 'Parach/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (360, 'Parach-Del/Tras', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (361, 'Bases/Parach-Delantero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (362, 'Bases/Parach-Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (363, 'Radiador', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (364, 'Radiador/Enf-Sistema/Direccion', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (365, 'Radiador/Enf-Transmision/Autom�tica', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (366, 'Compuerta/Trasera-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (367, 'Compuerta/Trasera-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (368, 'Compuertas/Traseras-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (369, 'Socalo/Lateral-Inferior/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (370, 'Socalo/Lateral-Inferior/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (371, 'Rejilla/Torpedo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (372, 'Rejilla/Torpedo-Lateral/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (373, 'Rejilla/Torpedo-Lateral/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (374, 'Furg�n/Aluminio-Completo', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (375, 'Cava/Termica-Purioretano/Inyectado', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (376, 'Defensa/Trasera', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (377, 'Plataforma/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (378, 'Panel/Frontal-Plataforma/Carga', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (379, 'Porta/Cauchos-Lateral/Repuesto', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (380, 'Astercooler', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (381, 'Estribo/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (382, 'Estribo/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (383, 'Estribos-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (384, 'Pescante/Externo-Lateral/Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (385, 'Pescante/Externo-Lateral/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (386, 'Pescantes/Externos-Laterales-Der/Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (387, 'Tapa/Maleta', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (388, 'Marco/Trasero', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (389, 'Paral/Delantero-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (390, 'Paral/Delantero-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (391, 'Paral/Central-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (392, 'Paral/Central-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (393, 'Paral/Trasero-Der', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (394, 'Paral/Trasero-Izq', 1);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (395, 'Capo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (396, 'Marco/Frontal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (397, 'Marco/Frontal-Superior', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (398, 'Cabina', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (399, 'Careta/Capo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (400, 'Extension/Frontal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (401, 'Marco/Cabina-Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (402, 'Panel/Frontal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (403, 'Panel/Posterior', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (404, 'Extension/Der-Panel/Frontal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (405, 'Extension/Izq-Panel/Frontal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (406, 'Borde/Guard-Del/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (407, 'Borde/Guard-Del/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (408, 'Borde/Guard-Tras/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (409, 'Borde/Guard-Tras/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (410, 'Borde/Puerta-Tras/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (411, 'Borde/Puerta-Tras/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (412, 'Panel/Lateral-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (413, 'Panel/Lateral-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (414, 'Panel/Lateral-Der/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (415, 'Panel/Lateral-Delantero/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (416, 'Panel/Lateral-Delantero/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (417, 'Panel/Lateral-Central/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (418, 'Panel/Lateral-Central/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (419, 'Panel/Lateral-Posterior/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (420, 'Panel/Lateral-Posterior/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (421, 'Estructura/Interna-Lateral/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (422, 'Estructura/Interna-Lateral/izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (423, 'Estructura/Interna-Der/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (424, 'Parach/Delantero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (425, 'Parach/Trasero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (426, 'Parach-Del/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (427, 'Bases/Parach-Delantero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (428, 'Bases/Parach-Trasero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (429, 'Radiador', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (430, 'Radiador/Enf-Sistema/Direccion', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (431, 'Radiador/Enf-Transmision/Autom�tica', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (432, 'Compuerta/Trasera-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (433, 'Compuerta/Trasera-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (434, 'Compuertas/Traseras-Der/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (435, 'Socalo/Lateral-Inferior/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (436, 'Socalo/Lateral-Inferior/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (437, 'Rejilla/Torpedo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (438, 'Porta/Cauchos-Lateral/Repuesto', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (439, 'Astercooler', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (440, 'Panel/Frontal-Plataforma/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (441, 'Estribo/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (442, 'Estribo/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (443, 'Estribos-Der/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (444, 'Pescante/Externo-Lateral/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (445, 'Pescante/Externo-Lateral/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (446, 'Pescantes/Externos-Laterales-Der/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (447, 'Tapa/Maleta', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (448, 'Marco/Trasero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (449, 'Paral/Delantero-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (450, 'Paral/Delantero-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (451, 'Paral/Central-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (452, 'Paral/Central-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (453, 'Paral/Trasero-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (454, 'Paral/Trasero-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (455, 'Guardafango/Del-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (456, 'Guardafango/Del-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (457, 'Guardafango/Del-Der/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (458, 'Guardafango/Tras-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (459, 'Guardafango/Tras-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (460, 'Guardafangos/Der-Del/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (461, 'Guardafangos/Izq-Del/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (462, 'Carter/Guardafango-Del/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (463, 'Carter/Guardafango-Del/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (464, 'Carter/Guardafango-Tras/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (465, 'Carter/Guardafango-Tras/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (466, 'Puerta/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (467, 'Puerta/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (468, 'Puerta/Del-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (469, 'Puerta/Del-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (470, 'Puerta/Tras-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (471, 'Puerta/Tras-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (472, 'Puertas/Der-Del/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (473, 'Puertas/Izq-Del/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (474, 'Babero/Del-Inferior', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (475, 'Babero/Tras-Inferior', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (476, 'Platina/Puerta-Del/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (477, 'Platina/Puerta-Del/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (478, 'Platinas/Puertas-Der-Del/tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (479, 'Platina/Puerta-Tras/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (480, 'Platina/Puerta-Tras/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (481, 'Platinas/Puertas-Izq-Del/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (482, 'Platina/Guard-Del/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (483, 'Platina/Guard-Del/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (484, 'Platina/Guard-Tras/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (485, 'Platina/Guard-Tras/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (486, 'Extension/Der-Parach/Del', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (487, 'Extensi�n/Izq-Parach/Del ', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (488, 'Extensiones/Laterales-Parach/Del', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (489, 'Extension/Der-Parach/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (490, 'Tubo/Escape', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (491, 'Extension/Izq-Parach/Trasero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (492, 'Extensiones/Laterales-Parach/Tras', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (493, 'Transmisi�n/Autom�tica-Veloc', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (494, 'Transmisi�n/Manual-Veloc', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (495, 'Compuerta/Trasera-Superior', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (496, 'Compuerta/Trasera-Inferior', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (497, 'Compuerta/Lateral-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (498, 'Compuerta/Lateral-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (499, 'Compuerta/Trasera-Caj�n/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (500, 'Guard/Der-Caj�n/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (501, 'Guard/Izq-Caj�n/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (502, 'Piso/Caj�n-Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (503, 'Panel/Frontal-Caj�n/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (504, 'Carter/Der-Caj�n/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (505, 'Carter/Izq-Caj�n/Carga', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (506, 'Piso/Delantero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (507, 'Carter/Maletero', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (508, 'Piso/Maleta', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (509, 'Manilla/Externa-Puerta/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (510, 'Manilla/Externa-Puerta/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (511, 'Manilla/Externa-Puerta/Del-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (512, 'Manilla/Externa-Puerta/Del-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (513, 'Manilla/Externa-Puerta/Tras-Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (514, 'Manilla/Externa-Puerta/Tras-Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (515, 'Manilla/Externa-Compuerta/Trasera', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (516, 'Tapa/Cubierta-Principal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (517, 'Encadenado/Deportivo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (518, 'Tapa/Protectora-Lateral/Der', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (519, 'Tapa/Protectora-Lateral/Izq', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (520, 'Tanque/Combustible', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (521, 'Marco/Chasis', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (522, 'Marco/Interno-Fibra/Frontal', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (523, 'Filler', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (524, 'Condensador-A/A', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (525, 'Techo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (526, 'Enderezar/Compacto', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (527, 'Enderezar/Bastidor', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (528, 'Cuadrar/Frente-Vehiculo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (529, 'Cuadrar/Parte-Posterior/Vehiculo', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (530, 'Carga/Ref-A/A', 2);
INSERT INTO `autopartes` (`id`, `nombre`, `tipoautoparte_id`) VALUES (531, 'Sustituir/Piezas-Mecanica', 2);

COMMIT;

-- -----------------------------------------------------
-- Data for table `code`
-- -----------------------------------------------------
START TRANSACTION;
USE `apasoftwarer`;
INSERT INTO `code` (`id`, `codigo`) VALUES (1, '06c49345f9f1a06718b33062cb885149');

COMMIT;
