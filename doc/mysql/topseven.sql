-- phpMyAdmin SQL Dump
-- version OVH
-- https://www.phpmyadmin.net/
--
-- Hôte : topseven.mysql.db
-- Généré le : ven. 31 déc. 2021 à 17:06
-- Version du serveur : 5.6.50-log
-- Version de PHP : 7.4.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `topseven`
--

-- --------------------------------------------------------

--
-- Structure de la table `calendar`
--

CREATE TABLE `calendar` (
  `season` tinyint(4) NOT NULL,
  `day` tinyint(4) NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `forum`
--

CREATE TABLE `forum` (
  `idx1` int(11) NOT NULL,
  `idx2` int(11) NOT NULL,
  `team` smallint(6) NOT NULL,
  `player` mediumint(9) NOT NULL,
  `season` tinyint(4) NOT NULL DEFAULT '0',
  `day` tinyint(4) NOT NULL,
  `date` datetime NOT NULL,
  `comment` text CHARACTER SET utf8mb4
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `match`
--

CREATE TABLE `match` (
  `id` int(11) NOT NULL,
  `season` tinyint(4) DEFAULT '0',
  `day` tinyint(4) NOT NULL,
  `team1` tinyint(4) NOT NULL COMMENT 'Equipe locale',
  `team2` tinyint(4) NOT NULL COMMENT 'Equipe visiteur',
  `date` date NOT NULL,
  `time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `password`
--

CREATE TABLE `password` (
  `Id` int(11) NOT NULL,
  `player` mediumint(9) NOT NULL,
  `status` tinyint(4) NOT NULL,
  `keyword` varchar(32) NOT NULL,
  `time` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `player`
--

CREATE TABLE `player` (
  `player_idx` mediumint(9) NOT NULL,
  `season` tinyint(4) NOT NULL DEFAULT '0',
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `name` varchar(50) NOT NULL,
  `pseudo` varchar(40) NOT NULL,
  `captain` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Capitaine',
  `rank` tinyint(4) NOT NULL,
  `rankFinal` tinyint(4) NOT NULL,
  `point` smallint(6) NOT NULL,
  `J` tinyint(4) NOT NULL COMMENT 'Joué',
  `G` tinyint(4) NOT NULL COMMENT 'Gagné',
  `N` tinyint(4) NOT NULL COMMENT 'Nul',
  `P` tinyint(4) NOT NULL COMMENT 'Perdu',
  `team` smallint(6) NOT NULL,
  `email` varchar(120) NOT NULL,
  `password` varchar(32) NOT NULL,
  `date_reg` datetime NOT NULL,
  `pm` int(11) NOT NULL COMMENT 'Points Marqués',
  `pe` int(11) NOT NULL COMMENT 'Points Encaissés',
  `ve` tinyint(4) NOT NULL COMMENT 'Victoires Extérieures',
  `evo` tinyint(4) NOT NULL COMMENT 'Evolution',
  `fun` int(11) NOT NULL COMMENT 'Points fun',
  `bd` tinyint(4) NOT NULL,
  `bo` tinyint(4) NOT NULL,
  `pc` tinyint(4) NOT NULL COMMENT 'Points coiffeur',
  `eq` tinyint(4) NOT NULL COMMENT 'Equipes différentes',
  `d14` tinyint(4) DEFAULT NULL COMMENT 'Journée pour 14 équipes différentes'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `prono`
--

CREATE TABLE `prono` (
  `id` int(11) NOT NULL,
  `season` tinyint(4) NOT NULL DEFAULT '0',
  `day` tinyint(4) NOT NULL,
  `player` smallint(6) NOT NULL,
  `match` mediumint(9) NOT NULL,
  `team` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `score`
--

CREATE TABLE `score` (
  `id` int(11) NOT NULL,
  `season` tinyint(4) NOT NULL DEFAULT '0',
  `day` tinyint(4) NOT NULL COMMENT 'Journée championnat',
  `team` tinyint(4) NOT NULL COMMENT 'Equipe championnat',
  `rank` tinyint(4) NOT NULL,
  `pm` smallint(6) NOT NULL COMMENT 'Points marqués',
  `pe` smallint(6) NOT NULL COMMENT 'Points encaissés',
  `pc` tinyint(4) NOT NULL COMMENT 'Points championnat',
  `bd` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Bonus défensif',
  `bo` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Bonus offensif',
  `em` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'Essais Marqués',
  `ee` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'Essais Encaissés',
  `ve` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Victoire extérieure',
  `J` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Joué',
  `V` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Victoire',
  `N` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Nul',
  `D` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Défaite'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `season`
--

CREATE TABLE `season` (
  `Id` tinyint(4) NOT NULL,
  `title` varchar(40) CHARACTER SET utf8 NOT NULL,
  `start` date NOT NULL,
  `start_register` date NOT NULL,
  `stop_register` date NOT NULL,
  `close_forum` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `team`
--

CREATE TABLE `team` (
  `team_short` text NOT NULL,
  `team_long` varchar(50) NOT NULL,
  `team_idx` tinyint(4) NOT NULL,
  `season` tinyint(4) NOT NULL,
  `previous_season` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `team_player`
--

CREATE TABLE `team_player` (
  `team_idx` smallint(6) NOT NULL,
  `name` varchar(50) NOT NULL,
  `season` tinyint(4) NOT NULL DEFAULT '0',
  `status` tinyint(4) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `calendar`
--
ALTER TABLE `calendar`
  ADD UNIQUE KEY `id` (`season`,`date`);

--
-- Index pour la table `forum`
--
ALTER TABLE `forum`
  ADD PRIMARY KEY (`idx1`);

--
-- Index pour la table `match`
--
ALTER TABLE `match`
  ADD PRIMARY KEY (`id`),
  ADD KEY `team1` (`team1`),
  ADD KEY `team2` (`team2`),
  ADD KEY `season_day` (`season`,`day`);

--
-- Index pour la table `password`
--
ALTER TABLE `password`
  ADD PRIMARY KEY (`Id`);

--
-- Index pour la table `player`
--
ALTER TABLE `player`
  ADD PRIMARY KEY (`player_idx`);

--
-- Index pour la table `prono`
--
ALTER TABLE `prono`
  ADD PRIMARY KEY (`id`),
  ADD KEY `day` (`day`),
  ADD KEY `player` (`player`);

--
-- Index pour la table `score`
--
ALTER TABLE `score`
  ADD PRIMARY KEY (`id`),
  ADD KEY `team_i` (`team`),
  ADD KEY `day_i` (`day`);

--
-- Index pour la table `season`
--
ALTER TABLE `season`
  ADD UNIQUE KEY `Id` (`Id`);

--
-- Index pour la table `team`
--
ALTER TABLE `team`
  ADD UNIQUE KEY `Idx` (`team_idx`,`season`);

--
-- Index pour la table `team_player`
--
ALTER TABLE `team_player`
  ADD UNIQUE KEY `team_idx` (`team_idx`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `forum`
--
ALTER TABLE `forum`
  MODIFY `idx1` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `match`
--
ALTER TABLE `match`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `password`
--
ALTER TABLE `password`
  MODIFY `Id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `player`
--
ALTER TABLE `player`
  MODIFY `player_idx` mediumint(9) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `prono`
--
ALTER TABLE `prono`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `score`
--
ALTER TABLE `score`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `team_player`
--
ALTER TABLE `team_player`
  MODIFY `team_idx` smallint(6) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
